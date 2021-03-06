##############################################################################
CONFIG = Debug
#CONFIG = Release

##############################################################################
.PHONY: all directory clean size

STACK_PATH = ../../..
APP_PATH = ..

CC = gcc
OBJCOPY = objcopy
SIZE = size

CFLAGS += -W -Wall --std=gnu99 -Os
CFLAGS += -fdata-sections -ffunction-sections -fpack-struct -fshort-enums
CFLAGS += -funsigned-char -funsigned-bitfields
#CFLAGS += -mmcu=atmega128rfa1
CFLAGS += -MD -MP -MT $(CONFIG)/$(*F).o -MF $(CONFIG)/$(@F).d

ifeq ($(CONFIG), Debug)
  CFLAGS += -g
endif

LDFLAGS += -Wl,--gc-sections
LDFLAGS += -mmcu=atmega256rfr2


INCLUDES += \
  -I$(STACK_PATH)/hal/atmega256rfr2/inc \
  -I$(STACK_PATH)/phy/atmegarfr2/inc \
  -I$(STACK_PATH)/nwk/inc \
  -I$(STACK_PATH)/sys/inc \
  -I$(STACK_PATH)/hal/drivers/atmega256rfr2 \
  -I$(APP_PATH) \
  -I/usr/lib/avr/include

SRCS += \
  $(STACK_PATH)/hal/atmega256rfr2/src/hal.c \
  $(STACK_PATH)/hal/atmega256rfr2/src/halTimer.c \
  $(STACK_PATH)/phy/atmegarfr2/src/phy.c \
  $(STACK_PATH)/nwk/src/nwk.c \
  $(STACK_PATH)/nwk/src/nwkDataReq.c \
  $(STACK_PATH)/nwk/src/nwkSecurity.c \
  $(STACK_PATH)/nwk/src/nwkFrame.c \
  $(STACK_PATH)/nwk/src/nwkGroup.c \
  $(STACK_PATH)/nwk/src/nwkRoute.c \
  $(STACK_PATH)/nwk/src/nwkRouteDiscovery.c \
  $(STACK_PATH)/nwk/src/nwkRx.c \
  $(STACK_PATH)/nwk/src/nwkTx.c \
  $(STACK_PATH)/sys/src/sys.c \
  $(STACK_PATH)/sys/src/sysTimer.c \
  $(STACK_PATH)/sys/src/sysEncrypt.c \
  $(STACK_PATH)/hal/drivers/atmega256rfr2/halUart.c \
  $(STACK_PATH)/hal/drivers/atmega256rfr2/halSleep.c \
  $(APP_PATH)/commands.c \
  $(APP_PATH)/WSNDemo.c 

DEFINES += \
  -DPHY_ATMEGARFR2 \
  -DHAL_ATMEGA256RFR2 \
  -DPLATFORM_RCB256RFR2 \
  -DF_CPU=8000000 

CFLAGS += $(INCLUDES) $(DEFINES)

OBJS = $(addprefix $(CONFIG)/, $(notdir %/$(subst .c,.o, $(SRCS))))

all: directory $(CONFIG)/WSNDemo.elf $(CONFIG)/WSNDemo.hex $(CONFIG)/WSNDemo.bin size

$(CONFIG)/WSNDemo.elf: $(OBJS)
	echo LD $@
	#$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(CONFIG)/WSNDemo.hex: $(CONFIG)/WSNDemo.elf
	echo OBJCOPY $@
	#$(OBJCOPY) -O ihex -R .eeprom $^ $@

$(CONFIG)/WSNDemo.bin: $(CONFIG)/WSNDemo.elf
	echo OBJCOPY $@
	#$(OBJCOPY) -O binary -R .eeprom $^ $@

%.o:
	echo CC $@
	$(CC) $(CFLAGS) $(filter %/$(subst .o,.c,$(notdir $@)), $(SRCS)) -c -o $@

directory:
	mkdir -p $(CONFIG)

size: $(CONFIG)/WSNDemo.elf
	echo size:
	#$(SIZE) -t $^

clean:
	echo clean
	-rm -rf $(CONFIG)

-include $(wildcard $(CONFIG)/*.d)
