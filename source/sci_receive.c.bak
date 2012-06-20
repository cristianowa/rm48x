#include "sci.h"
#include "sci_receive.h"
#include "sci_print.h"

void sciNotification(sciBASE_t *sci, uint32_t flags)
{
  if(flags &  SCI_RX_INT )
      sci_receive_rotine();

}

typedef enum curr_state_t  {
  SEND_DUMMY_PACKET,IDLE
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
  
 }
}

void send_dummy_packet(){
   print_line("Sending Dummy Packet");
   print_line("Press E to exit");
   if(sci_transfer_buffer[0] == 'e' || sci_transfer_buffer[0] == 'E' )
     curr_state= IDLE;
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
      case 'i':
      case 'I':
        curr_state = IDLE;
        break;
      case 'h':    
      case 'H':    
      default:
        print_line("current_state : ");
        print_curr_state();  
        print_line("press the following chars to select stade : ");        
        print_line("   SEND_DUMMY_PACKET : s");
        print_line("   IDLE : i");
  }
 else
 {
    switch(curr_state)
    {
      case SEND_DUMMY_PACKET:
          send_dummy_packet();
      break;  
      default:
         curr_state = IDLE;             
    }   
 }

  
}