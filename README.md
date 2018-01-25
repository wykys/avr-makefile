# AVR Makefile
Support for projects based on AVR microcontrollers. Makefile automatically finds source files and detects their dependencies. Which is a great companion to life.

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
# start avrdude terminal
make terminal
# EEPROM dump_eeprom
make dump_eeprom
# flash all (flash, EEPROM)
make flash_all
# chip testing
make chip_test
```

## Application notes
### File Template Hierarchy
```bash
.
├── bin
│   └── Makefile
├── inc
│   ├── settings.h
│   └── uart.h
├── LICENSE
├── Makefile
├── README.md
└── src
    ├── asm-fnc.S
    ├── main.c
    ├── rand.S
    └── uart.c

3 directories, 10 files
```
The source files `*.c` and `*.S` are located in the `src/` folder. Header files `*.h` are located in the `inc/` folder. The compilation outputs (binary files `*.hex`, `*.elf`, code disassembler `*.lss`, dependency files `*.list`, batch files `*.o`) and secondary `Makefile` are located in the `bin/` folder.


### Change of frequency
The `F_CPU` [Hz] constant used for delay functions is defined in the `settings.h` file. The `settings.h` file must be plugged into all the files in which you want to use the constant. You can also add additional constants that affect the behavior of the entire program.

```C
#ifndef F_CPU
  #define F_CPU 16000000UL // Hz
#endif
```

### Microprocessor change
Changing the microcontroller requires changing the `CHIP` variable in the` Makefile` file and the `MCU` variable in the `bin/ Makefile` file.

The `CHIP` variable is a parameter for `avrdude` and may contain the following values: http://www.nongnu.org/avrdude/user-manual/avrdude_4.html

The `MCU` variable is a parameter for `avr-gcc` and may contain the following values: https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html

For example, if I wanted ATmega328P (which is for example in arduino nano), I would make the following modifications:
```Makefile
# in Makefile
CHIP = m328p
# in bin/Makefile
MCU = atmega328p
```

### Programmer change
Changing the programmer will required change the value of `PROG` in` Makefile`. Possible parameters of the value that are passed to `avrdude` as `-c` are listed here: http://www.nongnu.org/avrdude/user-manual/avrdude_4.html

For example, if I wanted to use the arduino bootloader to flash the program, I would proceed as follows:
```Makefile
# in Makefile
PROG = arduino
```
