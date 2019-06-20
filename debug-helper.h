#ifndef DEBUG-HELPER_H
#define DEBUG-HELPER_H

#if DEBUG == true
#define DebugBegin(...) DEBUG_OI.begin(__VA_ARGS__)
#define DebugPrint(...) DEBUG_OI.print(__VA_ARGS__)
#define DebugPrintln(...) DEBUG_OI.println(__VA_ARGS__)
#define DebugPrintf(...) DEBUG_OI.printf(__VA_ARGS__)
#define DebugWrite(...) DEBUG_OI.write(__VA_ARGS__)
#define DebugFlush(...) DEBUG_OI.flush(__VA_ARGS__)
#else
// Define the counterparts that cause the compiler to generate no code
#define DebugBegin(...) (void(0))
#define DebugPrint(...) (void(0))
#define DebugPrintln(...) (void(0))
#define DebugPrintf(...) (void(0))
#define DebugWrite(...) (void(0))
#define DebugFlush(...) (void(0))
#endif

#endif