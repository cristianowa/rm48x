#include "sci.h"
#include "sci_receive.h"
#include "sci_print.h"
#include "mac.h"
#include "esm.h"
#include "parity_functions.h"

void sciNotification(sciBASE_t *sci, uint32_t flags)
{
  if(flags &  SCI_RX_INT )
      sci_receive_rotine();

}

typedef enum curr_state_t  {
  SEND_DUMMY_PACKET,IDLE,DUMP_MAC,PARITY_TEST,CLEAR_ESM
}curr_state_t;

curr_state_t curr_state = IDLE;

void print_curr_state()
{
 switch(curr_state)
 {
   case SEND_DUMMY_PACKET:
      print_line("   SEND_DUMMY_PACKET");
   break;
 case IDLE:
      print_line("   IDLE");
  break;
 case DUMP_MAC:
      print_line("   DUMP_MAC");
  break;
 case PARITY_TEST:
      print_line("   PARITY_TEST");
   break;
 case CLEAR_ESM:
      print_line("   CLEAR_ESM");
   break;
 }
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
     print_line("Parity Test ");
     print_line("  select the option :  ");
     print_line("  1 - DCAN1");
     print_line("  2 - DCAN2");
     print_line("  3 - DCAN3");
     print_line("  4 - MIBADC2");
     print_line("  5 - MIBADC1");
     int ch = sci_receive_byte();
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
void sci_receive_rotine()
{
  
 if( curr_state == IDLE)
  switch(sci_transfer_buffer[0])
  {
      case 's':
      case 'S':
        curr_state = SEND_DUMMY_PACKET;
        break;
      case 'd':
      case 'D':
        curr_state = DUMP_MAC;
        break;
      case 'i':
      case 'I':
        curr_state = IDLE;
        break;
      case 'p':
      case 'P':
        curr_state =PARITY_TEST ;
        break;
      case 'c':
      case 'C':
        curr_state = CLEAR_ESM;
        break;
      case 'h':    
      case 'H':    
      default:
        print_line("current_state : ");
        print_curr_state();  
        print_line("press the following chars to select stade : ");        
        print_line("   SEND_DUMMY_PACKET : s");
        print_line("   IDLE              : i");
        print_line("   DUMP_MAC          : d");
        print_line("   PARITY_TEST       : p");
        print_line("   CLEAR_ESM         : c");
        
  }
 else
 {
    switch(curr_state)
    {
      case SEND_DUMMY_PACKET:
          send_dummy_packet();
           curr_state = IDLE; 
      break;  
    case DUMP_MAC:
          dump_mac();
          curr_state = IDLE; 
      break;
    case PARITY_TEST:
           parity_test();
           curr_state = IDLE;
      break;
    case CLEAR_ESM:
           esmTriggerErrorPinReset();
           curr_state = IDLE;
      break;
      default:
         curr_state = IDLE;             
    }   
 }

  
}

int sci_receive_byte()
{
    sciDisableNotification(scilinREG,SCI_WAKE_INT |SCI_RX_INT |SCI_BREAK_INT );
    int ch = sciReceiveByte(scilinREG);
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