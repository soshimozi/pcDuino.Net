GCC=gcc

INSTALL_LOCATION=/usr/local/lib/

VERSION=1
NOVERSION_TARGET=libgpio.so
TARGET=$(NOVERSION_TARGET).$(VERSION)
OUTPUT=$(TARGET).0

LINKEROPTIONS=-soname,$(TARGET)
CFLAGS=-Wall -fPIC
LFLAGS=-shared -Wl,$(LINKEROPTIONS) -o $(OUTPUT)
OBJ=libgpio.o
SRCFILES=libgpio.c libgpio.h

%.o: %.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJ)
	$(GCC) -o $@ $^ $(LFLAGS)

all: $(OUTPUT)

install: $(OUTPUT)
	echo "Installing in $(INSTALL_LOCATION)"
	mv $(OUTPUT) $(INSTALL_LOCATION)
	ln -sf $(INSTALL_LOCATION)$(OUTPUT) $(INSTALL_LOCATION)$(TARGET)
	ln -sf $(INSTALL_LOCATION)$(TARGET) $(INSTALL_LOCATION)$(NOVERSION_TARGET)
	
clean:
	rm -rf $(OUTPUT)
	rm -rf $(OBJ)
