#include "UMachineCron.h"
#include <WProgram.h>
#include <HardwareSerial.h>

UMachineCron::UMachineCron(){
}

UMessage *UMachineCron::receive(UMessage *msg){
	UMachineCronMessage *cronMsg = (UMachineCronMessage *) msg;
	uint16_t count = 0;

	if(cronMsg == &tick){
		/* A tick message, process the pending tasks */
		cronMsg = (UMachineCronMessage *) tasks.start; 

		/*Cycle through messages decrease time variable*/

		while(cronMsg){
			count++;
			if(cronMsg->time)
				cronMsg->time--;

			cronMsg = (UMachineCronMessage *) cronMsg->next;
		}

		/* Plan: 
		 * Shift each message in turn off the que
		 * if time == 0 dispatch message
		 * else return to the que.
		 */

		while(count > 0){
			cronMsg = (UMachineCronMessage *) tasks.shift();
			if(cronMsg->time == 0){
				send(cronMsg,cronMsg->from);
			}else{
				tasks.add(cronMsg);
			}
			count--;
		}
	}else{
		/* Not a tick message add to the que. */
		if(cronMsg->repeat){
			cronMsg->time = cronMsg->repeat;
		}

		tasks.add((UMessage *)cronMsg);
	}

	return 0;
}
