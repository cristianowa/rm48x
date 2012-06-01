#include "task2.h"
#include "os_task.h"
#include "sci_print.h"
#include "can.h"
xTaskHandle xTask3Handle;


void vTask3(void *pvParameters)
{
  uint8_t tx_data[9] = { 'C','O','U','N','T',':',' ','0'};
    for(;;)
    {
        /* Send alive status to SCI */
              
          canTransmit(canREG1, canMESSAGE_BOX2,tx_data); 
          if(9 ==tx_data[8])
          {
            tx_data[8] = 0;
          }
          else
          {
            tx_data[8]++;
          }
          vTaskDelay(5000);
    }   
}