#include "task2.h"
#include "os_task.h"
#include "sci_print.h"
#include "can.h"
xTaskHandle xTask4Handle;

uint8_t  rx_data[9] = {0};

void vTask4(void *pvParameters)
{
    for(;;)
    {
        if(canIsRxMessageArrived(canREG2,canMESSAGE_BOX2))
        {
          canGetData(canREG2,canMESSAGE_BOX2 , rx_data);
          print("task 4 message received : ");
          print_line(rx_data);
        }
      
    }   
}