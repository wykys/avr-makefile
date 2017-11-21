# AVR Makefile
Support for projects based on AVR microcontrollers.  

## Installation on GNU/Linux
```bash
# my project template requires the following packages to be installed correctly:
# GCC compiler adapted for AVR architecture
sudo aptitude install gcc-avr
# basic libraries for AVR
sudo aptitude install avr-libc
# binary utilities
sudo aptitude install binutils-avr
# GNU make utility
sudo aptitude install make
```

## Use
```bash
# compiling the project, equivalen to make
make all
# flash content
make flash
# deletes the compilation outputs
make clean
# flash fuses, unsafe, attentive to the right fuses
make fuses
# start avrdude terminal
make terminal
# EEPROM dump_eeprom
make dump_eeprom
# flash all (flash, EEPROM fuses), unsafe, attentive to the right fuses
make flash_all
# chip testing
make chip_test
```

## Application notes
The template has the following structure
```bash
.
├── bin
│   └── Makefile
├── lib
│   ├── settings.h
│   └── uart.h
├── LICENSE
├── Makefile
├── README.md
└── src
    ├── asmFuncs.asm
    ├── main.c
    ├── rand.asm
    └── uart.c

3 directories, 10 files
```
The source files (`*.c` and `*.asm`) are located in the `src/` folder. Header files `*.h` are located in the `lib/` folder. The compilation outputs (binary files `*.hex`, `*.elf`, code disassembler `*.lss`, dependency files `*.list`, batch files `*.o`) and secondary `Makefile` are located in the `bin/` folder.

### Change of frequency
The `F_CPU` [Hz] constant used for delay functions is defined in the `settings.h` file. The `settings.h` file must be plugged into all the files in which you want to use the constant. You can also add additional constants that affect the behavior of the entire program.

```C
#ifndef F_CPU
  #define F_CPU 16000000UL // Hz
#endif
```

### Microprocessor change
Changing the microcontroller requires changing the `CHIP` variable in the` Makefile` file and the `MCU` variable in the `bin/ Makefile` file.

The `CHIP` variable is a parameter for` avrdude` and may contain the following values:
```
uc3a0512 = AT32UC3A0512
  c128     = AT90CAN128
  c32      = AT90CAN32
  c64      = AT90CAN64
  pwm2     = AT90PWM2
  pwm216   = AT90PWM216
  pwm2b    = AT90PWM2B
  pwm3     = AT90PWM3
  pwm316   = AT90PWM316
  pwm3b    = AT90PWM3B
  1200     = AT90S1200
  2313     = AT90S2313
  2333     = AT90S2333
  2343     = AT90S2343
  4414     = AT90S4414
  4433     = AT90S4433
  4434     = AT90S4434
  8515     = AT90S8515
  8535     = AT90S8535
  usb1286  = AT90USB1286
  usb1287  = AT90USB1287
  usb162   = AT90USB162
  usb646   = AT90USB646
  usb647   = AT90USB647
  usb82    = AT90USB82
  m103     = ATmega103
  m128     = ATmega128
  m1280    = ATmega1280
  m1281    = ATmega1281
  m1284    = ATmega1284
  m1284p   = ATmega1284P
  m1284rfr2 = ATmega1284RFR2
  m128rfa1 = ATmega128RFA1
  m128rfr2 = ATmega128RFR2
  m16      = ATmega16
  m161     = ATmega161
  m162     = ATmega162
  m163     = ATmega163
  m164p    = ATmega164P
  m168     = ATmega168
  m168p    = ATmega168P
  m169     = ATmega169
  m16u2    = ATmega16U2
  m2560    = ATmega2560
  m2561    = ATmega2561
  m2564rfr2 = ATmega2564RFR2
  m256rfr2 = ATmega256RFR2
  m32      = ATmega32
  m324p    = ATmega324P
  m324pa   = ATmega324PA
  m325     = ATmega325
  m3250    = ATmega3250
  m328     = ATmega328
  m328p    = ATmega328P
  m329     = ATmega329
  m3290    = ATmega3290
  m3290p   = ATmega3290P
  m329p    = ATmega329P
  m32m1    = ATmega32M1
  m32u2    = ATmega32U2
  m32u4    = ATmega32U4
  m406     = ATMEGA406
  m48      = ATmega48
  m48p     = ATmega48P
  m64      = ATmega64
  m640     = ATmega640
  m644     = ATmega644
  m644p    = ATmega644P
  m644rfr2 = ATmega644RFR2
  m645     = ATmega645
  m6450    = ATmega6450
  m649     = ATmega649
  m6490    = ATmega6490
  m64rfr2  = ATmega64RFR2
  m8       = ATmega8
  m8515    = ATmega8515
  m8535    = ATmega8535
  m88      = ATmega88
  m88p     = ATmega88P
  m8u2     = ATmega8U2
  t10      = ATtiny10
  t11      = ATtiny11
  t12      = ATtiny12
  t13      = ATtiny13
  t15      = ATtiny15
  t1634    = ATtiny1634
  t20      = ATtiny20
  t2313    = ATtiny2313
  t24      = ATtiny24
  t25      = ATtiny25
  t26      = ATtiny26
  t261     = ATtiny261
  t4       = ATtiny4
  t40      = ATtiny40
  t4313    = ATtiny4313
  t43u     = ATtiny43u
  t44      = ATtiny44
  t45      = ATtiny45
  t461     = ATtiny461
  t5       = ATtiny5
  t84      = ATtiny84
  t85      = ATtiny85
  t861     = ATtiny861
  t88      = ATtiny88
  t9       = ATtiny9
  x128a1   = ATxmega128A1
  x128a1d  = ATxmega128A1revD
  x128a1u  = ATxmega128A1U
  x128a3   = ATxmega128A3
  x128a3u  = ATxmega128A3U
  x128a4   = ATxmega128A4
  x128a4u  = ATxmega128A4U
  x128b1   = ATxmega128B1
  x128b3   = ATxmega128B3
  x128c3   = ATxmega128C3
  x128d3   = ATxmega128D3
  x128d4   = ATxmega128D4
  x16a4    = ATxmega16A4
  x16a4u   = ATxmega16A4U
  x16c4    = ATxmega16C4
  x16d4    = ATxmega16D4
  x16e5    = ATxmega16E5
  x192a1   = ATxmega192A1
  x192a3   = ATxmega192A3
  x192a3u  = ATxmega192A3U
  x192c3   = ATxmega192C3
  x192d3   = ATxmega192D3
  x256a1   = ATxmega256A1
  x256a3   = ATxmega256A3
  x256a3b  = ATxmega256A3B
  x256a3bu = ATxmega256A3BU
  x256a3u  = ATxmega256A3U
  x256c3   = ATxmega256C3
  x256d3   = ATxmega256D3
  x32a4    = ATxmega32A4
  x32a4u   = ATxmega32A4U
  x32c4    = ATxmega32C4
  x32d4    = ATxmega32D4
  x32e5    = ATxmega32E5
  x384c3   = ATxmega384C3
  x384d3   = ATxmega384D3
  x64a1    = ATxmega64A1
  x64a1u   = ATxmega64A1U
  x64a3    = ATxmega64A3
  x64a3u   = ATxmega64A3U
  x64a4    = ATxmega64A4
  x64a4u   = ATxmega64A4U
  x64b1    = ATxmega64B1
  x64b3    = ATxmega64B3
  x64c3    = ATxmega64C3
  x64d3    = ATxmega64D3
  x64d4    = ATxmega64D4
  x8e5     = ATxmega8E5
  ucr2     = deprecated, use 'uc3a0512'
```

The `MCU` variable is a parameter for `avr-gcc` and may contain the following values:
```
avr2
“Classic” devices with up to 8 KiB of program memory.
mcu = attiny22, attiny26, at90c8534, at90s2313, at90s2323, at90s2333, at90s2343, at90s4414, at90s4433, at90s4434, at90s8515, at90s8535.

avr25
“Classic” devices with up to 8 KiB of program memory and with the MOVW instruction.
mcu = ata5272, ata6616c, attiny13, attiny13a, attiny2313, attiny2313a, attiny24, attiny24a, attiny25, attiny261, attiny261a, attiny43u, attiny4313, attiny44, attiny44a, attiny441, attiny45, attiny461, attiny461a, attiny48, attiny828, attiny84, attiny84a, attiny841, attiny85, attiny861, attiny861a, attiny87, attiny88, at86rf401.

avr3
“Classic” devices with 16 KiB up to 64 KiB of program memory.
mcu = at43usb355, at76c711.

avr31
“Classic” devices with 128 KiB of program memory.
mcu = atmega103, at43usb320.

avr35
“Classic” devices with 16 KiB up to 64 KiB of program memory and with the MOVW instruction.
mcu = ata5505, ata6617c, ata664251, atmega16u2, atmega32u2, atmega8u2, attiny1634, attiny167, at90usb162, at90usb82.

avr4
“Enhanced” devices with up to 8 KiB of program memory.
mcu = ata6285, ata6286, ata6289, ata6612c, atmega48, atmega48a, atmega48p, atmega48pa, atmega48pb, atmega8, atmega8a, atmega8hva, atmega8515, atmega8535, atmega88, atmega88a, atmega88p, atmega88pa, atmega88pb, at90pwm1, at90pwm2, at90pwm2b, at90pwm3, at90pwm3b, at90pwm81.

avr5
“Enhanced” devices with 16 KiB up to 64 KiB of program memory.
mcu = ata5702m322, ata5782, ata5790, ata5790n, ata5791, ata5795, ata5831, ata6613c, ata6614q, ata8210, ata8510, atmega16, atmega16a, atmega16hva, atmega16hva2, atmega16hvb, atmega16hvbrevb, atmega16m1, atmega16u4, atmega161, atmega162, atmega163, atmega164a, atmega164p, atmega164pa, atmega165, atmega165a, atmega165p, atmega165pa, atmega168, atmega168a, atmega168p, atmega168pa, atmega168pb, atmega169, atmega169a, atmega169p, atmega169pa, atmega32, atmega32a, atmega32c1, atmega32hvb, atmega32hvbrevb, atmega32m1, atmega32u4, atmega32u6, atmega323, atmega324a, atmega324p, atmega324pa, atmega325, atmega325a, atmega325p, atmega325pa, atmega3250, atmega3250a, atmega3250p, atmega3250pa, atmega328, atmega328p, atmega328pb, atmega329, atmega329a, atmega329p, atmega329pa, atmega3290, atmega3290a, atmega3290p, atmega3290pa, atmega406, atmega64, atmega64a, atmega64c1, atmega64hve, atmega64hve2, atmega64m1, atmega64rfr2, atmega640, atmega644, atmega644a, atmega644p, atmega644pa, atmega644rfr2, atmega645, atmega645a, atmega645p, atmega6450, atmega6450a, atmega6450p, atmega649, atmega649a, atmega649p, atmega6490, atmega6490a, atmega6490p, at90can32, at90can64, at90pwm161, at90pwm216, at90pwm316, at90scr100, at90usb646, at90usb647, at94k, m3000.

avr51
“Enhanced” devices with 128 KiB of program memory.
mcu = atmega128, atmega128a, atmega128rfa1, atmega128rfr2, atmega1280, atmega1281, atmega1284, atmega1284p, atmega1284rfr2, at90can128, at90usb1286, at90usb1287.

avr6
“Enhanced” devices with 3-byte PC, i.e. with more than 128 KiB of program memory.
mcu = atmega256rfr2, atmega2560, atmega2561, atmega2564rfr2.

avrxmega2
“XMEGA” devices with more than 8 KiB and up to 64 KiB of program memory.
mcu = atxmega16a4, atxmega16a4u, atxmega16c4, atxmega16d4, atxmega16e5, atxmega32a4, atxmega32a4u, atxmega32c3, atxmega32c4, atxmega32d3, atxmega32d4, atxmega32e5, atxmega8e5.

avrxmega3
“XMEGA” devices with up to 64 KiB of combined program memory and RAM, and with program memory visible in the RAM address space.
mcu = attiny1614, attiny1616, attiny1617, attiny212, attiny214, attiny3214, attiny3216, attiny3217, attiny412, attiny414, attiny416, attiny417, attiny814, attiny816, attiny817.

avrxmega4
“XMEGA” devices with more than 64 KiB and up to 128 KiB of program memory.
mcu = atxmega64a3, atxmega64a3u, atxmega64a4u, atxmega64b1, atxmega64b3, atxmega64c3, atxmega64d3, atxmega64d4.

avrxmega5
“XMEGA” devices with more than 64 KiB and up to 128 KiB of program memory and more than 64 KiB of RAM.
mcu = atxmega64a1, atxmega64a1u.

avrxmega6
“XMEGA” devices with more than 128 KiB of program memory.
mcu = atxmega128a3, atxmega128a3u, atxmega128b1, atxmega128b3, atxmega128c3, atxmega128d3, atxmega128d4, atxmega192a3, atxmega192a3u, atxmega192c3, atxmega192d3, atxmega256a3, atxmega256a3b, atxmega256a3bu, atxmega256a3u, atxmega256c3, atxmega256d3, atxmega384c3, atxmega384d3.

avrxmega7
“XMEGA” devices with more than 128 KiB of program memory and more than 64 KiB of RAM.
mcu = atxmega128a1, atxmega128a1u, atxmega128a4u.

avrtiny
“TINY” Tiny core devices with 512 B up to 4 KiB of program memory.
mcu = attiny10, attiny20, attiny4, attiny40, attiny5, attiny9.

avr1
This ISA is implemented by the minimal AVR core and supported for assembler only.
mcu = attiny11, attiny12, attiny15, attiny28, at90s1200.
```
