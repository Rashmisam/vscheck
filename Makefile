CC=arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb  -O0
LDFLAGS = -nostdlib -T stm32_ls.ld
all: main.o stm32f407xx_gpio_driver.o stm32_startup.o my.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^
stm32f407xx_gpio_driver.o:stm32f407xx_gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^
my.elf: main.o stm32f407xx_gpio_driver.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	 rm -rf *.o *.elf