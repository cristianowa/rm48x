#include "sci.h"
#include "sci_receive.h"
#include "sci_print.h"
#include "mac.h"

#include "esm.h"
#include "parity_functions.h"
#include "can_protocol.h"
#include "string.h"
#include "stc.h"
#include "ccm.h"
void sciNotification(sciBASE_t *sci, uint32_t flags)
{
  if(flags &  SCI_RX_INT )
      sci_receive_rotine();

}


void send_dummy_packet(){
   print_line("Sending Dummy Packet");
   eth_dummy_send();   
}

void dump_mac(){
   print_line("Sending Dummy Packet");
   print_line("Press E to exit");
   dump_mac_state();

}


  
 void parity_test(){
     int ch;
		 print_line("Parity Test ");
     print_line("  select the option :  ");
     print_line("  1 - DCAN1");
     print_line("  2 - DCAN2");
     print_line("  3 - DCAN3");
     print_line("  4 - MIBADC2");
     print_line("  5 - MIBADC1");
     
     ch = sci_receive_byte();
     ch = ch - 48;
     switch(ch)
     {
     case 1:
       DCAN1_Parity();
       break;
     case 2:
       DCAN2_Parity();
       break;
     case 3:
       DCAN3_Parity();
       break;
     case 4:
       MIBADC2_Parity();
       break;
     case 5:
       MIBADC2_Parity();
       break;
     default :
       print_line("invalid option ");
     }
}



void sci_receive_string(uint8_t* str)
{
  uint8_t ch = 0; 
  uint8_t * tmp;
  tmp = str;
  while( 0xD != ch)
  {
    ch = sciReceiveByte(scilinREG);
    *tmp++ = ch;
  }
  *tmp = '\0';   
}

void can_send()
{

  uint8_t buf[100] = {0};
  print_line("type string to send : ");
  sci_receive_string(buf);
  can_protocol_send(canREG1,canMESSAGE_BOX1,buf,strlen((char*)buf));
}

void sci_receive_rotine()
{
  switch(sci_transfer_buffer[0])
  {
      case 's':
      case 'S':
          send_dummy_packet();
        break;
      case 'd':
      case 'D':
          dump_mac();
        break;
      case 'p':
      case 'P':
           parity_test();
        break;
      case 'e':
      case 'E':
          esmTriggerErrorPinReset();
        break;
      case 'c':
      case 'C':
        can_send();
      case 't':
      case 'T':
         stc_test();
        break; 
      case 'h':    
      case 'H':    
      default:
        print_line("press the following chars to select action : ");        
        print_line("   SEND_DUMMY_PACKET : s");
        print_line("   DUMP_MAC          : d");
        print_line("   PARITY_TEST       : p");
        print_line("   CLEAR_ESM         : e");
        print_line("   CAN_SEND          : c");
        print_line("   STC_TEST          : t");
    
  }
 
}

  


int sci_receive_byte()
{
		 int ch;
    sciDisableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
    ch = sciReceiveByte(scilinREG);
    sciEnableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
    return ch;
}

void sci_receive_wait(uint8_t ch)
{
    sciDisableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
    while(sciReceiveByte(scilinREG) != ch);
    sciEnableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
}

int sci_receive_key_pressed(uint8_t ch)
{
     int ret;
     sciDisableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
     if (sciReceiveByte(scilinREG) == ch)
          ret = 1;
     else
          ret = 0;
     sciEnableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );  
     return ret;
}

int promt_question(uint8_t* question)
{
  int answer;
  sciDisableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
  print(question);print_line(" (y/n) ");
  while(1)
  {
    int ch =  sciReceiveByte(scilinREG);
    if ('y' == ch)
      {
      answer = 1;
      break;
      }
    if ('n' == ch)
      {
      answer =  0;
      break;
      }
  }
  sciEnableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );    
  return answer;
}