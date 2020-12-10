#ifndef DEBUG_HELPER_H
#define DEBUG_HELPER_H

#if DEBUG == true
#define DebugBegin(...) DEBUG_OI.begin(__VA_ARGS__)
#define DebugPrint(...) DEBUG_OI.print(__VA_ARGS__)
#define DebugPrintln(...) DEBUG_OI.println(__VA_ARGS__)
#define DebugPrintf(...) DEBUG_OI.printf(__VA_ARGS__)
#define DebugWrite(...) DEBUG_OI.write(__VA_ARGS__)
#define DebugFlush(...) DEBUG_OI.flush(__VA_ARGS__)
#if defined ARDUINO_ARCH_ESP8266
#define DebugInfo(...)                                                                                                            \
  {                                                                                                                               \
    DEBUG_OI.println("");                                                                                                         \
    DEBUG_OI.println(F("====================== DEBUG INFO START ======================"));                                        \
    DEBUG_OI.print(F("Build date/time:         "));                                                                               \
    DEBUG_OI.println(__DATE__ ", " __TIME__);                                                                                     \
    DEBUG_OI.print(F("Core version:            "));                                                                               \
    DEBUG_OI.println(ESP.getCoreVersion());                                                                                       \
    DEBUG_OI.print(F("SDK version:             "));                                                                               \
    DEBUG_OI.println(ESP.getSdkVersion());                                                                                        \
    DEBUG_OI.print(F("Boot version:            "));                                                                               \
    DEBUG_OI.println(ESP.getBootVersion());                                                                                       \
    DEBUG_OI.println();                                                                                                           \
    DEBUG_OI.print(F("Boot mode:               "));                                                                               \
    DEBUG_OI.println(ESP.getBootMode());                                                                                          \
    DEBUG_OI.print(F("Reset cause:             "));                                                                               \
    DEBUG_OI.println(ESP.getResetReason());                                                                                       \
    DEBUG_OI.println();                                                                                                           \
    DEBUG_OI.print(F("Chip ID:                 0x"));                                                                             \
    DEBUG_OI.println(ESP.getChipId(), HEX);                                                                                       \
    DEBUG_OI.print(F("CPU frequency (MHz):     "));                                                                               \
    DEBUG_OI.println(ESP.getCpuFreqMHz());                                                                                        \
    DEBUG_OI.println();                                                                                                           \
    DEBUG_OI.print(F("Flash Chip ID:           0x"));                                                                             \
    DEBUG_OI.println(ESP.getFlashChipId(), HEX);                                                                                  \
    DEBUG_OI.print(F("Flash Chip Mode:         "));                                                                               \
    DEBUG_OI.println(ESP.getFlashChipMode());                                                                                     \
    DEBUG_OI.print(F("Flash Chip Size (SDK):   "));                                                                               \
    DEBUG_OI.println(ESP.getFlashChipSize());                                                                                     \
    DEBUG_OI.print(F("Flash Chip Size (ID):    "));                                                                               \
    DEBUG_OI.println(ESP.getFlashChipRealSize());                                                                                 \
    DEBUG_OI.println();                                                                                                           \
    DEBUG_OI.printf("Sketch size/left:        %u / %u\n", ESP.getSketchSize(), ESP.getFreeSketchSpace());                         \
    DEBUG_OI.printf("Sketch usage:            %u%%\n", ((ESP.getFreeSketchSpace() + ESP.getSketchSize()) / ESP.getSketchSize())); \
    DEBUG_OI.print(F("Sketch MD5:              "));                                                                               \
    DEBUG_OI.println(ESP.getSketchMD5());                                                                                         \
    DEBUG_OI.print(F("Heap free:               "));                                                                               \
    DEBUG_OI.println(ESP.getFreeHeap());                                                                                          \
    DEBUG_OI.println(F("======================= DEBUG INFO END ======================="));                                        \
  }
#else
#define DebugInfo(...)                                                                     \
  {                                                                                        \
    DEBUG_OI.println("");                                                                  \
    DEBUG_OI.println(F("====================== DEBUG INFO START ======================")); \
    DEBUG_OI.print(F("Build date/time:         "));                                        \
    DEBUG_OI.println(__DATE__ ", " __TIME__);                                              \
    DEBUG_OI.println(F("======================= DEBUG INFO END =======================")); \
  }
#endif
#else
// Define the counterparts that cause the compiler to generate no code
#define DebugBegin(...) (void(0))
#define DebugPrint(...) (void(0))
#define DebugPrintln(...) (void(0))
#define DebugPrintf(...) (void(0))
#define DebugWrite(...) (void(0))
#define DebugFlush(...) (void(0))
#define DebugInfo() (void(0))
#endif

#endif