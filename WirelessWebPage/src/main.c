#include "pico/stdio.h"
#include "pico/cyw43_arch.h"
#include "lwip/apps/httpd.h"
#include "lwipopts.h"
#include "ssi.h"
#include "cgi.h"

const char WIFI_SSID[] = "ssid";
const char WIFI_PASSWORD[] = "password";

int main()
{
	stdio_init_all();

	cyw43_arch_init();

	cyw43_arch_enable_sta_mode();

	while (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000) != 0)
	{
		printf("Attempring to connect to %s ...\n", WIFI_SSID);
	}

	printf("Connected!\n");

	httpd_init();
	printf("Http server initialised\n");

	ssi_init();
	printf("SSI handler initialised\n");

	cgi_init();
	printf("CGI handler initialised\n");

	while (1)
	{
	}
}