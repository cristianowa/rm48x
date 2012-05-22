#include "can_protocol.h"
#include "can.h"
#include "debug.h"
#include "sci_print.h"
#define MAXIMUM_MESSAGE_SIZE 1500

int message_arrived = 0;

/*
CAN PROTOCOL
receives byte to byte
scape char is 0x5C('\') and terminate char is 0xB ( enter )
to send '\' must send '\' twice and to send 'enter' must send '\'
*/

uint8_t message_buffer[MAXIMUM_MESSAGE_SIZE] = {0};
int buffer_index = 0;

int escape = 0;


void can_protocol_receive_fragment( can_buffer fragment)
{
  
    int i =0;
    for(i = 0; i < 8; i++)
    {
       if( escape )
       {
         message_buffer[buffer_index] = fragment[i];
         buffer_index++;
         escape = 0;
       }
       else
       {
           switch(fragment[i])
           {
           case '\\':
             escape = 1;
             break;
           case 0xB:
             can_protocol_message_arrived(message_buffer);
             buffer_index = 0;
             break;
           default:
             message_buffer[buffer_index] = fragment[i];
             buffer_index++;                  
           }
       }
    }
}

void can_protocol_send(canBASE_t * node,uint32_t msg_box,uint8_t* message,int size)
{
  int i =0;
  int j =0;
  can_buffer fragment;
  #ifdef  __CAN_PROTOCOL__DEBUG__
   print_line(" CAN PROTOCOL : can_protocol_send");
  #endif  
  for(i = 0;i < size;i+=8)
  {
     for( j = 0;j<8;j++)
     {
       if(size == i + j )
       {//done transmiting, can put the mark and is done
         fragment[j] = 0xB;
         break;
       }
       else
       {       
         switch( message[i+j])
         {
          case 0xB:
            fragment[j++] = 0x5C;
            fragment[j] = 0xB;                        
            break;
          case 0x5C:
            fragment[j++] = 0x5C;
            fragment[j] = 0x5C;                        
            break;
          default:
          fragment[j] =  message[i+j] ;          
         }
       }         
     }
     #ifdef  __CAN_PROTOCOL__DEBUG__
       print(" CAN PROTOCOL : sending fragment :");
       print_line( fragment);
    #endif
     canTransmit(node, msg_box, fragment); 
  }
}


void canMessageNotification(canBASE_t *node, uint32_t messageBox)
{
  uint8_t  rx_data[9] = {0};
#ifdef __CAN__DEBUG__
  print("CAN INTERRUPT : ");
    switch((int)node)
    {
    case 0xFFF7DC00U:
      print("  canREG1 : ");
      break;
    case 0xFFF7DE00U:
      print("  canREG2 : ");      
      break;
    case 0xFFF7E000U:
      print("  canREG3 - ");
      break;
    }    
    print(" msg box : ");
    print_number(messageBox);
    print_line("");
#endif

    while(!canIsRxMessageArrived(node, messageBox));
    canGetData(node, messageBox, rx_data);  /* receive on can2  */
    print(" CAN Message : ");
    print_line(rx_data);
    can_protocol_receive_fragment(rx_data);

}

void can_protocol_message_arrived(uint8_t* message)
{
#ifdef  __CAN_PROTOCOL__DEBUG__
   print_line(" CAN PROTOCOL : can_protocol_message_arrived");
   print_line("message");
   print_line(message_buffer);
#endif
  
  
}

