/**
 * CallbackDispatcher
 *
 */

#include "UMachineCallback.h"
#include <HardwareSerial.h>

UMachineCallback::UMachineCallback(UMachineCron *c){
	cron = c;
}

UMessage *UMachineCallback::receive(UMessage *msg){
	UCallbackMessage *cbMsg = (UCallbackMessage *)msg;

	if(msg->from == cron){
		(cbMsg->callback)(cbMsg->data);
		if(cbMsg->repeat){
			return cbMsg;
		}else{
			return NULL;
		}
	}else{
		send(cbMsg,cron);
		return NULL;
	}
}
