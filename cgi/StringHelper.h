#ifndef _StringHelper_H
#define _StringHelper_H

#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
	
//	std::string buffer(s.c_str());
//	
//	size_t pos = 0;
//	std::string token;
//	while ((pos = buffer.find(delim)) != std::string::npos) {
//		token = buffer.substr(0, pos);
//		elems.push_back(token);
//		buffer.erase(0, pos + delim.length());
//	}
//	
//	if(buffer.size() > 0)
//		elems.push_back(buffer);
		
    return elems;
	
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

#endif