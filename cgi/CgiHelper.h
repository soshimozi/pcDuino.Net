#ifndef _CGI_HELPER_H
#define _CGI_HELPER_H

#include <string>
#include <vector>
#include <map>
#include <utility>

class CgiHelper
{
private:
	std::multimap<std::string, std::string> m_formValues;
	std::map<std::string, std::string> m_serverVariables;
	
	void ParseRequest(void);
	void ReadHeaders(void);
	void ReadEnvVar(const char *);
	void ReadFormData(void);
	
protected:
	
public:

	CgiHelper();
	~CgiHelper();
	
	std::string HTTP_REFERER() { return m_serverVariables["HTTP_REFERER"]; }
	std::string HTTP_USER_AGENT() { return m_serverVariables["HTTP_USER_AGENT"]; }
	std::string HTTP_ACCEPT() { return m_serverVariables["HTTP_ACCEPT"]; }
	std::string CONTENT_LENGTH() { return m_serverVariables["CONTENT_LENGTH"]; }
	std::string CONTENT_TYPE() { return m_serverVariables["CONTENT_TYPE"]; }
	std::string REMOTE_IDENT() { return m_serverVariables["REMOTE_IDENT"]; }
	std::string REMOTE_USER() { return m_serverVariables["REMOTE_USER"]; }
	std::string AUTH_TYPE() { return m_serverVariables["AUTH_TYPE"]; }
	std::string REMOTE_ADDR() { return m_serverVariables["REMOTE_ADDR"]; }
	std::string QUERY_STRING() { return m_serverVariables["QUERY_STRING"]; }
	std::string SCRIPT_NAME() { return m_serverVariables["SCRIPT_NAME"]; }
	std::string PATH_TRANSLATED() { return m_serverVariables["PATH_TRANSLATED"]; }
	std::string PATH_INFO() { return m_serverVariables["PATH_INFO"]; }
	std::string REQUEST_METHOD() { return m_serverVariables["REQUEST_METHOD"]; }
	std::string SERVER_PORT() { return m_serverVariables["SERVER_PORT"]; }
	std::string SERVER_PROTOCOL() { return m_serverVariables["SERVER_PROTOCOL"]; }
	std::string GATEWAY_INTERFACE() { return m_serverVariables["GATEWAY_INTERFACE"]; }
	std::string SERVER_NAME() { return m_serverVariables["SERVER_NAME"]; }
	std::string SERVER_SOFTWARE() { return m_serverVariables["SERVER_SOFTWARE"]; }
	std::string HTTP_COOKIE() { return m_serverVariables["HTTP_COOKIE"]; }
	
	std::vector<std::string> GetFormValues(std::string);
	std::vector< std::pair<std::string, std::string> > GetFormVariables(void);
};
#endif
