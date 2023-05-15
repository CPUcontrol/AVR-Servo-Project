CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -Os -DF_CPU=8000000L -mmcu=atmega328p
LDFLAGS=-mmcu=atmega328p

BIN=image

${BIN}.hex: ${BIN}.elf
	${OBJCOPY} -O ihex -R .eeprom $< $@

${BIN}.elf: servo.o analog.o main.o
	${CC} -o $@ $^ ${LDFLAGS}

install: ${BIN}.hex
	avrdude -p m328p -c usbtiny -U flash:w:$<:i -B 20

clean:
	rm *.elf *.hex *.o
