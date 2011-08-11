
#ifndef __CALLBACK_MESSAGE
#define __CALLBACK_MESSAGE

#include <UMachineCron.h>
#include <UMessage.h>

class UCallbackMessage : public UMachineCronMessage {

	public:
		UCallbackMessage(void (*fn) (void *data),void *data,unsigned long time,unsigned long repeat);

		void (*callback) (void *data);
		void *data;
};

#endif
