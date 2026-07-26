#ifndef KONTIME_H
#define KONTIME_H

/*** definition ***/

double kon_getTime(void);

/*** implementation ***/

#ifdef KONTIME_IMPLEMENTATION

#if defined(__linux__) || defined(__unix__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)

#define _POSIX_C_SOURCE 200809L
#include <time.h>

double kon_getTime(void) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);

  return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9; 
}

#endif /* end of unix / posix compliant systems */

#if defined(_WIN32)

#include <windows.h>

double kon_getTime(void) {
	LARGE_INTEGER freq, now;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&now);

	return (double)now.QuadPart / (double)freq.QuadPart;
}

#endif /* end of windows implementation */

#endif /* end of KONTIME_IMPLEMENTATION */


#endif
