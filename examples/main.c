#define KONTIME_IMPLEMENTATION
#include "kontime.h"

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void) {
	kon_time lastTime = kon_getTime();

	puts("Hello, World!");
	printf("9 + 10 = %d\n", 9 + 10);

	kon_time currentTime = kon_getTime();

	kon_time deltaTime = currentTime - lastTime;
		
	printf("The time that passed while running the functions was: %lf\n", deltaTime);

	return EXIT_SUCCESS;
}
