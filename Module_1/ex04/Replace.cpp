#include "Replace.h"

const char *ft_add(std::string dest, std::string src) {

	std::size_t found = dest.find(".");
	std::string tmp;
	if (found == std::string::npos) {
		tmp += dest.substr(0, found);
		tmp += src;
	}
	tmp += dest.substr(0, found);
	tmp += src;
	// tmp += dest.substr(found);
	return tmp.c_str() ;
}

std::string ft_replace(std::string s1, std::string s2, std::string line) {
	std::size_t found = line.find(s1);
	while (found != std::string::npos) {
		std::string tmp;
		tmp += line.substr(0, found);
		tmp += s2;
		tmp += line.substr(found + s1.length());
		line = tmp;
		found = line.find(s1, found+1);
	}
	return line; 

}