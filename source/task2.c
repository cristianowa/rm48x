#include "task2.h"
#include "os_task.h"
#include "sci_print.h"

xTaskHandle xTask2Handle;

void vTask2(void *pvParameters)
{
    for(;;)
    {
        /* Send alive status to SCI */
        print_line("Task 2 Alive");
        vTaskDelay(10000);
    }   
}