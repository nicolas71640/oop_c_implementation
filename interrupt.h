
#ifndef INTERRUPT_DEF
#define INTERRUPT_DEF

#include "stdint.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "subject.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_INTERRUPTS_NUMBER	10



/*STRUCTURES AND ENUMERATIONS*/
typedef struct Interrupt Interrupt;
struct Interrupt{
	/*SuperClass*/
	Subject *super;

	/*Attributes*/
	Observer *observer;
	
	/*Public Methods*/
	bool (*addObserver)(Interrupt * const self, void * object_instance, void (*handler)(void*,void*));
};

/*PROTOTYPES*/
Interrupt *Interrupt_Create(void);
bool Interrupt_addObserver(Interrupt * const self, void * object_instance, void (*handler)(void*,void*));
void Interrupt_ISR(void);

#endif
