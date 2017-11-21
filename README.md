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
