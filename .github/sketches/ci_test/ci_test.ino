// DEBUG is injected via build flags (-DDEBUG=1 or -DDEBUG=0) by CI
#define DEBUG_OI Serial

#include <debug-helper.h>

void setup() {
  DebugBegin(115200);
  DebugInfo();
  DebugPrintln("CI compile check");
}

void loop() {
  DebugPrint("tick: ");
  DebugPrintln(millis());
}
