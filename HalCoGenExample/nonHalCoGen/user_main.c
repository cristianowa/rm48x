#ifndef USER_MAIN_C_
#define USER_MAIN_C_
#include "user_main.h"
#include "nonHalCoGen/leds_control.h"
void user_main(void)
{
	leds_init();
	led_on(LED_CTRL_LED_3);
	led_on(LED_CTRL_LED_4);
	led_on(LED_CTRL_LED_5);
	led_on(LED_CTRL_LED_5);
	return;
}

#endif /*USER_MAIN_C_*/
