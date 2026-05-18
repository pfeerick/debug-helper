# DebugHelper

Zero-overhead conditional debug macros for Arduino, ESP8266, and ESP32.

When `DEBUG` is not enabled, every macro expands to `void(0)` — the compiler eliminates all debug code entirely, adding nothing to flash or RAM.

## Installation

**PlatformIO** — add to `platformio.ini`:
```ini
lib_deps =
    https://github.com/pfeerick/debug-helper.git
```

**Arduino IDE** — install via Library Manager (search for `DebugHelper`) or download the ZIP and use Sketch → Include Library → Add .ZIP Library.

## Usage

Define `DEBUG` and `DEBUG_OI` **before** including the header:

```cpp
#define DEBUG true      // remove or set to false to strip all debug code
#define DEBUG_OI Serial // any Stream-compatible object (Serial, Serial1, etc.)

#include <debug-helper.h>
```

### Macros

| Macro | Description |
|---|---|
| `DebugBegin(baud)` | Initialize the debug output stream |
| `DebugPrint(...)` | `print()` passthrough |
| `DebugPrintln(...)` | `println()` passthrough |
| `DebugPrintf(...)` | `printf()` passthrough |
| `DebugWrite(...)` | `write()` passthrough |
| `DebugFlush(...)` | `flush()` passthrough |
| `DebugInfo()` | Print platform info block (see below) |

### DebugInfo() output

`DebugInfo()` prints a formatted block to the debug stream. The content is platform-specific:

- **ESP8266** — core/SDK/boot version, chip ID, CPU frequency, flash details, sketch size & MD5, heap free & fragmentation
- **ESP32** — IDF version, chip model/revision/cores, CPU frequency, flash size, sketch size & MD5, heap free/min/max-alloc
- **Generic Arduino** — build date and time only

### Disabling debug

Set `DEBUG` to `false` or remove the define entirely. All macros expand to `void(0)` and the compiler generates no debug code.

## License

MIT
