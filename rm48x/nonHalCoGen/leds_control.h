#ifndef LEDS_CONTROL_H_
#define LEDS_CONTROL_H_
/*LEDS POSITION

	3		4		5
		 _______
       	|       |
    1  	|  uC   |	2
       	|_______|

	8		7		6

*/
typedef enum LEDS_CTRL
{LED_CTRL_LED_1_RED = 16, 
LED_CTRL_LED_1_GREEN = 4,
LED_CTRL_LED_1_BLUE = 27, 
LED_CTRL_LED_2_RED = 20,
LED_CTRL_LED_2_GREEN = 2, 
LED_CTRL_LED_2_BLUE = 5,
LED_CTRL_LED_3 =17,
LED_CTRL_LED_4 = 31,
LED_CTRL_LED_5 = 0,
LED_CTRL_LED_6 = 25,
LED_CTRL_LED_7 = 18,
LED_CTRL_LED_8 = 19}led;

#define LED_CTRL_ON 1
#define LED_CTRL_OFF 0
void leds_init(void);

void led_on(led ledIndex);

void led_off(led ledIndex);
#endif /*LEDS_CONTROL_H_*/
