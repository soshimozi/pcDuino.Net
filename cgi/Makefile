CXX=g++

INCLUDEDIRS= -I/home/ubuntu/src/libgpio -I.
LIBS=-lgpio
LFLAGS=$(LIBS)
CFLAGS=-Wall $(INCLUDEDIRS)

DEPS=CgiHelper.h RequestCookie.h ResponseCookie.h StringHelper.h
OBJS=GpioCgi.o CgiHelper.o RequestCookie.o ResponseCookie.o

%.cpp: $(DEPS)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

gpio.cgi: $(OBJS) 
	$(CXX) -o $@ $^ $(LFLAGS)
	
all: gpio.cgi

install: gpio.cgi
	echo "Installing ..."
	mv gpio.cgi /usr/lib/cgi-bin/
	
clean:
	rm -rf gpio.cgi
	rm -rf *.o

