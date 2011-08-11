/**
 * MicroMachinesCron
 *
 * Perform period actions
 */

#ifndef __U_MACHINE_CRON
#define __U_MACHINE_CRON

#include <avr/interrupt.h>
#include <UMachine.h>
#include <UMachineCronMessage.h>

class UMachineCron : public UMachine {

	public:
		UMachineCron();
		UMessage *receive(UMessage *msg);

		UMachineCronMessage tick;
		UMessageList tasks;
};
#endif
