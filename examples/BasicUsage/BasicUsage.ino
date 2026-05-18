// Enable debug output. Remove or set to false to eliminate all debug code at compile time.
#define DEBUG true
#define DEBUG_OI Serial

#include <debug-helper.h>

unsigned long lastPrint = 0;

void setup() {
  DebugBegin(115200);
  delay(500);

  // Prints build date/time and platform-specific info (chip, flash, heap, etc.)
  DebugInfo();
}

void loop() {
  if (millis() - lastPrint >= 5000) {
    lastPrint = millis();
    DebugPrint("Uptime (ms): ");
    DebugPrintln(millis());
  }
}
