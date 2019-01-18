#ifndef EQUIMETRE_DEF
#define EQUIMETRE_DEF

#include "stdio.h"
#include "windows.h"
#include "accelerometer.h"
#include "barometer.h"
#include "gps.h"
#include "timer.h"
#include <unistd.h>
#include <sys/time.h>
#include "util.h"
#include "button.h"


/*PREPROCESSOR DIRECTIVES*/
#define MAX_SENSORS_NUMBER 10
#define MAIN_TIMER_FREQUENCY 100
/*PROTOTYPES*/

void equimetre_main(uint8_t timerId);
void *equimetre_init(void* id);

#endif

