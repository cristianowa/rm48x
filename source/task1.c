#include "task1.h"
#include "os_task.h"
#include "gio.h"
#include "het.h"

xTaskHandle xTask1Handle;

void vTask1(void *pvParameters)
{
    for(;;)
    {
        /* Taggle HET[1] with timer tick */
        gioSetBit(hetPORT1, 17, gioGetBit(hetPORT1, 17) ^ 1);
        vTaskDelay(100);
    }   
}