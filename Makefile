PROCESSOR=-mthumb -mcpu=cortex-m0 -DHSI48_VALUE="((uint32_t)48000000)" -DSTM32F072xB

INCLUDES=-Iinclude

OBJS+=src/libdw3000.o src/libdw3000Spi.o src/mac_802_15_4.o

CFLAGS+=$(PROCESSOR) $(INCLUDES) -O0 -g3 -Wall -Wno-pointer-sign -std=gnu11 -ffunction-sections -fdata-sections
PREFIX=arm-none-eabi-

CC=$(PREFIX)gcc
OBJCOPY=$(PREFIX)objcopy

all: $(OBJS)

clean:
	rm -f $(OBJS)
