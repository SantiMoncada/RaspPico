#include "pico/stdlib.h"
#include <stdio.h>

#define GPIO_ON 1
#define GPIO_OFF 0

#define LED_PIN 25

int main()
{
    char name[30];

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        gpio_put(LED_PIN, GPIO_ON);

        printf("Hello whats your name?\n");
        scanf("%s", name);
        printf("Oh, Hello %s \n", name);
        gpio_put(LED_PIN, GPIO_OFF);
        sleep_ms(1000);
    }
}