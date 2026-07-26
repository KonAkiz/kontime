# KONTIME

![License](https://img.shields.io/badge/license-MIT-blue)
![Language](https://img.shields.io/badge/language-C99-orange)

## About

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
double last_time = kon_getTime();

/* after some time has passed */
double current_time = kon_getTime();

/* some people refer to this as deltaTime or elapsedTime */
double elapsedTime = current_time - last_time;
```
This is how you usually calculate how much time has passed.

## Examples

If you wish to see my examples, you can check my [examples dir/folder](examples) or my [main.c file](examples/main.c).

## License - [MIT License](LICENSE)
