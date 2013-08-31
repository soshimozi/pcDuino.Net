#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

#include <vector>

#include <libgpio.h> 

#include "CgiHelper.h"

using namespace std;

int main() 
{

	gpio_open();
	setPinMode(3, MODE_OUTPUT);
	setPinValue(3, LOW);

	
	//print header
	CgiHelper helper;

	std::string ledvalue = "";
	
	vector<std::string> ledvalues = helper.GetFormValues("led");
	if(ledvalues.size() > 0) {
		ledvalue = ledvalues[0];
		
		// check for value being "on"
		if(!strcasecmp(ledvalues[0].c_str(), "on"))
		{
			setPinValue(3, HIGH);
		} 
		else
		{
			setPinValue(3, LOW);
		}
	}
	
	gpio_close();
	
	// cout << "HTTP/1.1 303" << endl;
	cout << "Set-Cookie: ledval=" << ledvalue << "; Path=/" << endl;
	cout << "Location: " << helper.HTTP_REFERER() << endl;
	cout << endl;
	
	// cout << "<html><title>Test</title><body>" << endl;
	
	// cout << "cookie: " << helper.HTTP_COOKIE() << endl;
	// cout << "</body></html>" << endl;
	// cout << endl;
	
	return 1;
}
