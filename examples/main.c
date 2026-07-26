#define KONTIME_IMPLEMENTATION
#include "kontime.h"

#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void) {
	puts("Hello, World!");

	printf("The time we got was: %lf\n", kon_getTime());

	return EXIT_SUCCESS;
}
