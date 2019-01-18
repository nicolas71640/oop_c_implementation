#include "usart.h"
static Usart mUsarts[MAX_USARTS_NUMBER];
static int mIterator = 0;

/* 
*	\brief Init the suject
*/
Usart *Usart_Create(void){

	Usart *self = mUsarts + mIterator++;

	self->super = Subject_Create();

	/*Override*/
	self->init = Usart_init;
	self->addObserver = Usart_addObserver;

	return self;
}

bool Usart_init(Usart * const self, int frequency){
	self->timerId = timer_add(Usart_ISR,frequency);
}

bool Usart_addObserver(Usart * const self, void * object_instance, void (*handler)(void*,void*)){
	Observer *observer = Observer_Create();
	observer->init(observer,handler,object_instance);	
	self->super->addObserver(self->super,observer);
}

void Usart_ISR(uint8_t timerId){
	for(uint8_t i = 0 ; i <= mIterator ; i++){
		if(mUsarts[i].timerId == timerId){
			Subject_notifyObservers(mUsarts[i].super,NULL);	
			return;
		}
	}

}

