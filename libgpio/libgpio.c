#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "libgpio.h"

// These arrays will become file descriptors for the 18 IO pin and mode files.
int pinMode[18];
int pinData[18];

#define GPIO_PIN_PATH "/sys/devices/virtual/misc/gpio/pin/"
#define GPIO_MODE_PATH "/sys/devices/virtual/misc/gpio/mode/"
#define GPIO_FILENAME "gpio"

void setPin(int, int);
void setMode(int, int);

unsigned char getPin(int);
unsigned char getMode(int);

unsigned char readFile(int);
void writeFile(int, int);

void gpio_open() {

	int i;
	char path[256]; // nice, long buffer to hold the path name for pin access

	// This first loop does four things:
	//   - initialize the file descriptors for the pin mode files
	//   - initialize the file descriptors for the pin data files
	//   - make the pins outputs
	//   - set all the pins low
	for (i = 0; i < 18; i++) {

		memset(path,0,sizeof(path));
		sprintf(path, "%s%s%d", GPIO_MODE_PATH, GPIO_FILENAME, i);
		pinMode[i] = open(path, O_RDWR);

		memset(path,0,sizeof(path));
		sprintf(path, "%s%s%d", GPIO_PIN_PATH, GPIO_FILENAME, i);
		pinData[i] = open(path, O_RDWR);
	}
}

void gpio_close() {
	int i;
	for (i = 0; i < 18; i++) {
		close(pinData[i]);
		close(pinMode[i]);
	}
}

/*************************************************************************/
/*                   Public Functions                                    */
/*									 */
/*************************************************************************/
void setPinMode(int pinIndex, unsigned char mode) {
	setMode(pinMode[pinIndex], (int)mode);
}

unsigned char getPinMode(int pinIndex) {
	return getMode(pinMode[pinIndex]);
}

void setPinValue(int pinIndex, unsigned char val) {
	setPin(pinData[pinIndex], (int)val);
}

unsigned char getPinValue(int pinIndex) {
	return getPin(pinData[pinIndex]);
}

/****************************************************************************/
/*                      Private functions and wrappers                      */
/****************************************************************************/


// These two 'set' functions are just wrappers to the writeFile() function to
//   make the code prettier.
void setMode(int pinID, int mode) {
	writeFile(pinID, mode);
}

unsigned char getMode(int pinID) {
	return readFile(pinID);
}

void setPin(int pinID, int state) {
  writeFile(pinID, state);
}

unsigned char getPin(int pinID) {
	return readFile(pinID);
}

// While it seems okay to only *read* the first value from the file, you
//   seemingly must write four bytes to the file to get the I/O setting to
//   work properly. This function does that.
void writeFile(int fileID, int value) {
	char buffer[4];  // A place to build our four-byte string.
	memset((void *)buffer, 0, sizeof(buffer)); // clear the buffer out.
	sprintf(buffer, "%c", value);
	lseek(fileID, 0, SEEK_SET);   // Make sure we're at the top of the file!
	write(fileID, buffer, sizeof(buffer));
}

unsigned char readFile(int fileID) {
	unsigned char buffer;
	read(fileID, &buffer, 1);
	return buffer;
}


