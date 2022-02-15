# PS/2 Keyboard Support Library for Raspberry Pico

Keyboard signals are decoded using a PIO state machine
then converted to ASCII code by the library.

## Wiring

There are 4 wires in the PS/2 keyboard interface.

![multi pico carrier](images/ps2_male.png)

```
V+    Connect to Pico 3.3V pin
GND   Connect to Pico ground pin
DATA  Connect to GPIO14 pin
CLOCK Connect to GPIO15 pin
```
**NOTE**: PS/2 keyboards were designed to operate at 5V. These connections
assume that yours will operate correctly at 3.3V volts. Not all do.
**Under no circumstance try powering at 5V without also implementing
level shifting for the clock and data, otherwise you could damage
the GPIO ports.**

## Building the project from source

Pre-requisite: git c pico-sdk 

```
git clone https://github.com/lurk101/pico-ps2kbd.git
cd pico-ps2kbd
git submodule update --init
mkdir b
cd b
cmake ..
make
```
## API
```
// Initialize PS/2 keyboard support
// Parameters
//     pio  - keyboard suport pio number. 0 or 1
//     gpio - GPIO number of data pin, ctl pin must be on next
//            adjacent GPIO
// Returns  - none
void kbd_init(uint pio, uint gpio);

// Return keyboard status
// Parameters - none
// Returns  - 0 for not ready, otherwise ready
int kbd_ready(void);

// Blocking keyboard read
// Parameters - none
// Returns  - single ASCII character
char kbd_getc(void);
```
## Example output
```
PS/2 KDB example
The quick brown fox jumps over the lazy dog
```
