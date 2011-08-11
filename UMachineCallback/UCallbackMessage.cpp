#include "UCallbackMessage.h"

UCallbackMessage::UCallbackMessage(void (*fn) (void *data),void *d,unsigned long t,unsigned long r) : UMachineCronMessage() {
	callback = fn;
	data = d;
	time = t;
	repeat = r;
}
