#ifndef DEF_TIMER_H
#define DEF_TIMER_H
#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"
#include <unistd.h>
#include "util.h"
#include <time.h>
/*PREPROCESSOR DIRECTIVES*/
#define MAX_TIMERS_NUMBER 10

/*STRUCTURES*/
typedef struct{
	/*Attributes*/
	void (*handler)(uint8_t);
	uint32_t frequency;
	pthread_t tid;
}Timer;


/*PROTOTYPES*/
uint8_t timer_add(void (*handler)(uint8_t), uint32_t mseconds);
void timer_start();



#endif
