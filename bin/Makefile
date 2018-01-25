# wykys Makefile for AVR

ifndef NAME
NAME = PRJ
endif

SRC = ../src/
LIB = ../inc/

MCU = atmega16

CC=avr-gcc -fdiagnostics-color=always
CFLAGS = -mmcu=$(MCU) -Wall -std=c99 -O1 -I $(LIB)
AFLAGS = -mmcu=$(MCU) -Wall -x assembler-with-cpp

OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
BINSIZE = avr-size
RM = rm -rf

DEP = dependence.list

OBJFILES = $(shell find $(SRC) -name '*.c' -printf '%f ' | sed -e 's/\.c/\.o/g')
OBJFILES += $(shell find $(SRC) -name '*.S' -printf '%f ' | sed -e 's/\.S/\.o/g')

.PHONY: dependence clean $(NAME)

# build all
all: $(NAME)

# genereting dependence
$(DEP): $(SRC)*.c
	$(CC) -I $(LIB) -MM $(SRC)*.c > $(DEP)

# include genereted dependence
-include $(DEP)

# create object modules
%.o : $(SRC)%.c
	$(CC) -c $(CFLAGS) $< -o $@
%.o: $(SRC)%.S
	$(CC) -c $(AFLAGS) $< -o $@

# create ELF
$(NAME).elf: $(DEP) $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $@

# create HEX
$(NAME).hex: $(NAME).elf
	$(OBJCOPY) -R .eeprom -O ihex $(NAME).elf $(NAME).hex

# create EEPROM
EEP.hex: $(NAME).elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $(NAME).elf $@

# disassembly EFL
$(NAME).lss: $(NAME).elf
	$(OBJDUMP)  -h -S $(NAME).elf > $@

# analyze size ELF
$(NAME): $(NAME).elf $(NAME).hex EEP.hex $(NAME).lss
	@$(BINSIZE) -C --mcu=$(MCU) $(NAME).elf

# clean files
clean:
	$(RM) *.o *.list *.elf *.hex *.lss
