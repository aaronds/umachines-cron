/**
 * A 'Ticker' to send a message to a machine when millis changes.
 *
 * Intended as a low-tec way to drive UMachineCron
 *
 * TODO: Replace with a timer interupt.
 */

#ifndef __U_MACHINE_MILLIS_TICKER
#define __U_MACHINE_MILLIS_TICKER

#include <UMachine.h>

class UMachineMillisTicker : public UMachine {

	public:
		unsigned long lastMillis;
		UMessage loop;
		UMessage *tick;
		UMachine *machine;

		UMachineMillisTicker(UMachine *m,UMessage *t);
		UMessage *receive(UMessage *m);
};

#endif
