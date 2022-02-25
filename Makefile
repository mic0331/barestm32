PROGRAM=barestm32
OBJECTS=main.o startup_stm32f401re.o

TARGET_FLAGS=\
	--specs=nosys.specs\
	-mcpu=cortex-m4\
	-mthumb\
	-mlittle-endian\
	-mfpu=fpv4-sp-d16\
	-mfloat-abi=hard\
	-nostdlib\
	-mthumb-interwork

CFLAGS=\
	-g -Wall -Wextra -Werror\
	$(TARGET_FLAGS)

LDFLAGS=\
	$(TARGET_FLAGS)\
	-Wl,-v,-Tstm32f401re.ld

%.o: %.c
	arm-none-eabi-gcc $(CFLAGS) -c -o $@ $<

%.o: %.s
	arm-none-eabi-gcc $(CFLAGS) -c -o $@ $<

$(PROGRAM): $(OBJECTS)	
	arm-none-eabi-gcc $(LDFLAGS) -o $@ $(OBJECTS)

flash: $(PROGRAM)
	openocd -f openocd.cfg -c "program $(PROGRAM) verify reset exit"

gdb:
	arm-none-eabi-gdb -q $(PROGRAM) -x gdb.cfg

clean:
	rm *.o $(PROGRAM)

.PHONY: flash clean gdb