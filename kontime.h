#ifndef KONTIME_H
#define KONTIME_H

/*** definition ***/

typedef double kon_time;

kon_time kon_getTime(void);

/*** implementation ***/

#ifdef KONTIME_IMPLEMENTATION

#if defined(__linux__) || defined(__unix__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)

#define _POSIX_C_SOURCE 200809L
#include <time.h>

kon_time kon_getTime(void) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);

  return (kon_time)ts.tv_sec + (kon_time)ts.tv_nsec / 1e9; 
}

#elif defined(_WIN32)

#include <windows.h>

kon_time kon_getTime(void) {
	LARGE_INTEGER freq, now;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&now);

	return (kon_time)now.QuadPart / (kon_time)freq.QuadPart;
}

#else
#error "kontime.h: unsupported platform!"

#endif

#endif /* end of KONTIME_IMPLEMENTATION */


#endif
