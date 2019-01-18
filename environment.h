#ifndef DEF_ENVIRONNMENT
#define DEF_ENVIRONNMENT

#include "stdio.h"
#include "pthread.h"
#include "windows.h" //To get the Sleep method
#include "equimetre.h"
#include <unistd.h>
#include <time.h>
#include "interrupt.h"

void* environment_main(void* id);

#endif
