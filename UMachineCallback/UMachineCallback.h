/**
 * A machine for dispatching periodic or timed callbacks
 */

#ifndef __U_MACHINE_CALLBACK_DISPATCHER
#define __U_MACHINE_CALLBACK_DISPATCHER

#include <avr/interrupt.h>
#include <UMachine.h>
#include <UMachineCron.h>
#include <UMachineCronMessage.h>

#include "UCallbackMessage.h"

class UMachineCallback : public UMachine {

	public:
		UMachineCron *cron;

		UMachineCallback(UMachineCron *cron);
		UMessage *receive(UMessage *);
};

#endif
