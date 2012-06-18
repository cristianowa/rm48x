#include "task2.h"
#include "os_task.h"
#include "sci_print.h"
#include "parity_functions.h"
#include "esm.h"

xTaskHandle xTask2Handle;

void vTask2(void *pvParameters)
{
    int counter = 0;
    for(;;)
    {
      /* simple way to switch tasks */
      counter++;
      if(counter > 20)
      {
        counter = 0; 
      }
      print("T2 : actual counter : ");
      print_number(counter);
      print_line("");
      /* detect errors every cycle */
      if( esmREG->ESTATUS4[0U] | esmREG->ESTATUS4 [1U] )
      {   
          /*Should test if is ESM test or a error, in the example 
          app just says it and reset esm pin */
          print_line("error_detected");           
          esmTriggerErrorPinReset();
      }         

      switch(counter)
      {
          case 0:
            DCAN1_Parity();
            break;
          case 1:
            DCAN3_Parity();
            break;
          case 2:
            
            break;
      }
      
      vTaskDelay(1000);
    }   
}