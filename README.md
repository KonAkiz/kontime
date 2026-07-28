# KONTIME
## KonAki's Minimal Time Library

![License](https://img.shields.io/badge/license-MIT-blue)
![Language](https://img.shields.io/badge/language-C99-orange)

## About

This library only gives you functions to mark the time. and sleep a specific amount of time on both windows and linux.

This project was made just because I got annoyed with constantly reimplementing this thing for my different projects. I won't be maintaining this much because this is sort of simple to do and seems like it's pretty much finished.

This is another one of those single-header-libraries that you can just drop into your project.

This was specifically made with c99 in mind. You can read about it through [this wiki page](https://en.wikipedia.org/wiki/C99) or this [full standard text](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf).

## Usage

You don't have to build this even though I've included a [Makefile](Makefile). That was just for compiling the example.

As I've said before, just drag the [header file](kontime.h) into the project you wish to use it in. **HOWEVER**: you will need one **AND ONLY ONE** file that defines KONTIME_IMPLEMENTATION. You define it like this:
```c
#define KONTIME_IMPLEMENTATION
#include "kontime.h"
```

If you ever need to calculate elapsed time... just do the delta time formula. current time minus previous time.
```c
kon_time last_time = kon_getTime();

/* after some time has passed */
kon_time current_time = kon_getTime();

/* some people refer to this as deltaTime or elapsedTime */
kon_time elapsedTime = current_time - last_time;
```
This is how you usually calculate how much time has passed.

If you ever need to make a program sleep, use kon_sleep.
```c
kon_time seconds = 1.0; /* literally just a single second */

kon_sleep(seconds);
```

For those who are curious, kon_time is just a double.

### Something to note

If you are ever compiling with a strict standard for c99
```sh
cc -std=c99 main.c
```
Then please define #define _POSIX_C_SOURCE 200809L.

You can define it in your c files **STRICTLY BEFORE** including your headers.
```c
#define _POSIX_C_SOURCE 200809L
#define KONTIME_IMPLEMENTATION
#include "kontime.h"
```

or during compile time.
```sh
cc -std=c99 main.c -D_POSIX_C_SOURCE=200809L
```

## Examples

If you wish to see my examples, you can check my [examples dir/folder](examples) or my [main.c file](examples/main.c).

## License - [MIT License](LICENSE)
