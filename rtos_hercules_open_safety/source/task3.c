#include "task2.h"
#include "os_task.h"
#include "sci_print.h"
#include "can.h"
xTaskHandle xTask3Handle;



void vTask3(void *pvParameters)
{
  uint8_t data[9] = { 'C','O','U','N','T',':',' ','0'};
  
    canTransmit(canREG1, canMESSAGE_BOX2,data); 
    for(;;)
    {
       
        while(!canIsRxMessageArrived(canREG1,canMESSAGE_BOX1))
        {
         vTaskDelay(50); 
        }
        canGetData(canREG1,canMESSAGE_BOX1 , data);
        print("task 3 message received : ");
        print_line(data);
        if((48+9) ==data[7])
        {
           data[7] = 48;
        }
        else
        {
          data[7]++;
        }
        print("task 3 message send : ");
        print_line(data);      
        canTransmit(canREG1, canMESSAGE_BOX2,data); 
        vTaskDelay(5000);   
    }   
}