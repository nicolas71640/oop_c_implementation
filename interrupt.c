#include "interrupt.h"
static Interrupt mInterrupts[MAX_INTERRUPTS_NUMBER];
static int mIterator = 0;

/* 
*	\brief Init the suject
*/
Interrupt *Interrupt_Create(void){

	Interrupt *self = mInterrupts + mIterator++;

	self->super = Subject_Create();

	/*Override*/
	self->addObserver = Interrupt_addObserver;

	return self;
}


bool Interrupt_addObserver(Interrupt * const self, void * object_instance, void (*handler)(void*,void*)){
	Observer *observer = Observer_Create();
	observer->init(observer,handler,object_instance);	

	self->super->addObserver(self->super,observer);
}

void Interrupt_ISR(){
	Subject_notifyObservers(mInterrupts[0].super,NULL);	
}

