
#ifndef USART_DEF
#define USART_DEF

#include "stdint.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "subject.h"
#include "timer.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_USARTS_NUMBER	10



/*STRUCTURES AND ENUMERATIONS*/
typedef struct Usart Usart;
struct Usart{
	/*SuperClass*/
	Subject *super;

	/*Attributes*/
	Observer *observer;
	int timerId;
	
	/*Public Methods*/
	bool (*init)(Usart * const self, int frequency);
	bool (*addObserver)(Usart * const self, void * object_instance, void (*handler)(void*,void*));
	bool (*sendBytes)(Usart * const self);
};

/*PROTOTYPES*/
Usart *Usart_Create(void);
bool Usart_init(Usart * const self, int frequency);
bool Usart_addObserver(Usart * const self, void * object_instance, void (*handler)(void*,void*));
void Usart_ISR(uint8_t timerId);

#endif
