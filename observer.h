
#ifndef OBSERVER_DEF
#define OBSERVER_DEF

#include "stdint.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_OBSERVERS_NUMBER	10


/*STRUCTURES AND ENUMERATIONS*/
typedef struct Observer Observer;
struct Observer{
	/*Attributes*/
	void (*handler)(void * object_instance,void * data);
	void *object_instance;

	/*Public Methods*/
	bool (*init)(Observer * const self, void (*handler)(void*,void*),void * object_instance);
};

/*PROTOTYPES*/
Observer *Observer_Create(void);
bool Observer_init(Observer * const self, void (*handler)(void *,void *),void * object_instance);

#endif
