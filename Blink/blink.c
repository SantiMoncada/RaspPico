#include "pico/stdlib.h"
#include <stdio.h>

#define GPIO_ON 1
#define GPIO_OFF 0

#define LED_PIN 25

int main()
{
	stdio_init_all();

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	while (true)
	{
		gpio_put(LED_PIN, GPIO_ON);
		printf("LED ON\n");
		sleep_ms(2000);

		printf("LED OFF\n");
		gpio_put(LED_PIN, GPIO_OFF);
		sleep_ms(2000);
	}
}
