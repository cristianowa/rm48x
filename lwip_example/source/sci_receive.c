#include "sci.h"
#include "sci_receive.h"
#include "sci_print.h"
#include "can_protocol.h"
#include "string.h"
void sciNotification(sciBASE_t *sci, uint32_t flags)
{
  if(flags &  SCI_RX_INT )
      sci_receive_rotine();

}

typedef enum curr_state_t  {
  SEND_DUMMY_PACKET,IDLE,DUMP_MAC,CAN_SEND
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
  case CAN_SEND:
      print_line("   CAN_SEND");
  break; 
 }
}

void send_dummy_packet(){
   print_line("Sending Dummy Packet");
  
}

void dump_mac(){
   print_line("Sending Dummy Packet");
   print_line("Press E to exit");

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
  print_line("type string to send : ");
  uint8_t buf[100] = {0};
  sci_receive_string(buf);
  can_protocol_send(canREG1,canMESSAGE_BOX1,buf,strlen((char*)buf)); 
  curr_state = IDLE;       
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
      case 'c':
      case 'C':
        curr_state = CAN_SEND;
      case 'h':    
      case 'H':    
      default:
        print_line("current_state : ");
        print_curr_state();  
        print_line("press the following chars to select stade : ");        
        print_line("   SEND_DUMMY_PACKET : s");
        print_line("   IDLE : i");
        print_line("   DUMP_MAC: d");
        print_line("   CAN_SEND: c");
        
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
    case CAN_SEND:
        can_send();
          break;
      default:
         curr_state = IDLE;             
    }   
 }

  
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