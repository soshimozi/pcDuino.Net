#include <stdlib.h>     /* strtol */
#include <stdio.h>

#include "CgiHelper.h"
#include "StringHelper.h"

#include <sstream>
#include <iostream>

using namespace std;

CgiHelper::CgiHelper()
{
	ParseRequest();
}

CgiHelper::~CgiHelper()
{
}

void CgiHelper::ReadEnvVar(const char * var)
{
	char * pval = NULL;
	
	pval = getenv(var);
	if( pval )
		m_serverVariables.insert(pair<string, string>(var, pval));
}

void CgiHelper::ReadHeaders(void)
{
	ReadEnvVar("HTTP_COOKIE");
	ReadEnvVar("SERVER_NAME");
	ReadEnvVar("SERVER_SOFTWARE");
	ReadEnvVar("GATEWAY_INTERFACE");
	ReadEnvVar("SERVER_PROTOCOL");
	ReadEnvVar("SERVER_PORT");
	ReadEnvVar("REQUEST_METHOD");
	ReadEnvVar("PATH_INFO");
	ReadEnvVar("PATH_TRANSLATED");
	ReadEnvVar("SCRIPT_NAME");
	ReadEnvVar("QUERY_STRING");
	ReadEnvVar("REMOTE_HOST");
	ReadEnvVar("REMOTE_ADDR");
	ReadEnvVar("AUTH_TYPE");
	ReadEnvVar("REMOTE_USER");
	ReadEnvVar("REMOTE_IDENT");
	ReadEnvVar("CONTENT_TYPE");
	ReadEnvVar("CONTENT_LENGTH");
	ReadEnvVar("HTTP_ACCEPT");
	ReadEnvVar("HTTP_USER_AGENT");
	ReadEnvVar("HTTP_REFERER");
}

void CgiHelper::ParseRequest(void)
{
	ReadHeaders();
	ReadFormData();
}


void CgiHelper::ReadFormData(void)
{
	ostringstream formdata;
	
	int ch;
	while ((ch = cin.get(), !cin.eof())) {
		switch (ch) {
			default: formdata << char(ch); 	break;
			case '+': formdata << ' ';		break;
			case '&': formdata << '\n';		break;
			case '%': {
				char buf[3];
				buf[0] = cin.get();
				buf[1] = cin.get();
				buf[2] = '\0';
				formdata << char(strtol(buf, 0, 16));
				break;
			} // case
		} // switch
	} // while	
	
	// now parse it
	std::string formdatastring(formdata.str());
	
	// split on space to get name/value pairs
	vector<string> pairs = split(formdatastring, '\n');
	
	for(vector<string>::const_iterator it=pairs.begin(); it!=pairs.end(); it++ ) {
		vector<string> namevaluepair = split((*it), '=');
		
		if(namevaluepair.size() == 2) {
			m_formValues.insert(pair<string, string>(namevaluepair[0], namevaluepair[1]));
		}
	}
}

std::vector< pair<std::string, std::string> > CgiHelper::GetFormVariables(void)
{
	vector< pair<string,string> > names;
	
	for(  multimap<string, string>::iterator it = m_formValues.begin(); it != m_formValues.end(); it++)
	{
		names.push_back((*it));
	}
	
	return names;
}


std::vector<std::string> CgiHelper::GetFormValues(std::string key)
{
	vector<string> values;
	
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ppp;
	// equal_range(b) returns pair<iterator,iterator> representing the range
	// of element with key
	ppp = m_formValues.equal_range(key);
	
	for (multimap<string, string>::iterator it = ppp.first; it != ppp.second; ++it)
	{
		values.push_back((*it).second);
	}
	
	return values;
}