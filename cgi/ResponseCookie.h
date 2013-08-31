#ifndef _RESPONSE_COOKIE_H
#define _RESPONSE_COOKIE_H

#include <string>

class ResponseCookie
{
	public:
	std::string Domain() const { return m_domain; }
	void Domain(std::string val) { m_domain = val; }
		
	long Expires() const { return m_expirationTimeStamp; }
	void Expires(long val) { m_expirationTimeStamp = val; }
	
	bool IsSecure() const { return m_secure; }
	void IsSecure(bool val) { m_secure = val; }
	
	bool IsHttpOnly() const { return m_httpOnly; }
	void IsHttpOnly(bool val) { m_httpOnly = val; }
	
	std::string Path() const { return m_path; }
	void Path(std::string val) { m_path = val; } 
		
	void Parse(std::string);
	
	ResponseCookie() {}
	~ResponseCookie() {}
	
	private:
		long m_expirationTimeStamp;
		std::string m_domain;
		bool m_secure;
		bool m_httpOnly;
		std::string m_path;
			
	protected:
};
	
#endif