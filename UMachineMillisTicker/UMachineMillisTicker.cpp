#include "UMachineMillisTicker.h"
#include <WProgram.h>

UMachineMillisTicker::UMachineMillisTicker(UMachine *m,UMessage *t) : UMachine() {
	lastMillis = 0;
	machine = m;
	tick = t;
}

UMessage *UMachineMillisTicker::receive(UMessage *msg){

	/* As of this moment i'm not sure if cron should return 
	 * tick message.
	 */
	
	if(msg == &loop){
		if(lastMillis != millis()){
			lastMillis = millis();

			/* Safty checks hopefully unessisary */

			if(!tick->next && __uMachineDispatchMessageList.end != tick){
				send(tick,machine);
			}
		}
		send(&loop,this);
	}

	return NULL;
}
