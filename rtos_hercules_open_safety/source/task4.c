#include "task2.h"
#include "os_task.h"
#include "sci_print.h"
#include "can.h"
xTaskHandle xTask4Handle;



void vTask4(void *pvParameters)
{
    for(;;)
    {
        uint8_t data[9] = { 'C','O','U','N','T',':',' ','0'};
      
        while(!canIsRxMessageArrived(canREG2,canMESSAGE_BOX2))
        {
         vTaskDelay(50); 
        }        canGetData(canREG2,canMESSAGE_BOX2 , data);
        print("task 4 message received : ");
        print_line(data);
        if((48+9) ==data[7])
        {
           data[7] = 48;
        }
        else
        {
          data[7]++;
        }
        print("task 4 message send : ");
        print_line(data);
        canTransmit(canREG2, canMESSAGE_BOX1,data);
        vTaskDelay(5000); 
    }   
}