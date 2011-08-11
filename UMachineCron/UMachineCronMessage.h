/**
 * MicroMachineCronMessage
 *
 */

#ifndef __U_MACHINE_CRON_MESSAGE
#define __U_MACHINE_CRON_MESSAGE 

#include <UMessage.h>

class UMachineCronMessage : public UMessage {
	public:
		UMachineCronMessage();
		unsigned long time;
		unsigned long repeat;
};

#endif
