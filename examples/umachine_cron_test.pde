#include <UMessage.h>
#include <UMessageList.h>
#include <UMachine.h>
#include <UMachineDispatch.h>
#include <UMachineCronMessage.h>
#include <UMachineCron.h>
#include <UMachineMillisTicker.h>
#include <UCallbackMessage.h>
#include <UMachineCallback.h>

UMachineCron uCron = UMachineCron();
UMachineMillisTicker uMillisTicker = UMachineMillisTicker(&uCron,&uCron.tick);

void sayHello(void *data);

UMachineCallback uCallbackDispatcher = UMachineCallback(&uCron);
UCallbackMessage uSayHelloMessage = UCallbackMessage(&sayHello,NULL,0,1000);

void setup(){
  Serial.begin(9600);
  Serial.println("Starting");
  uMillisTicker.send(&uMillisTicker.loop,&uMillisTicker);
  uCallbackDispatcher.send(&uSayHelloMessage,&uCallbackDispatcher);
  Serial.println("Done");
}

void sayHello(void *data){
  Serial.println("Test");
}
