#include "environment.h"

void* environment_main(void* id){
	printf("ENVIRONMENT MAIN START");

	/*Main Environment Loop*/	
	for(;;){
		Sleep(5000);
		Interrupt_ISR();
	}

	


	return NULL;

}/*environnment_main*/
