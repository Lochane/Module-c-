/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:05:01 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/16 18:27:41 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinData::BitcoinData() {
	
}

BitcoinData::~BitcoinData() {}

// BitcoinData::BitcoinData(const BitcoinData& rhs) {}

// BitcoinData& BitcoinData::operator=(const BitcoinData&rhs){
	
// }

bool BitcoinData::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

std::string TrimZero(std::string line){
  std::string res = line;

  if (res[0] == 0){
    res[0] == res[1];
    res[1] == NULL;
}
 return res;
}

void BitcoinData::CheckFormat(std::string line){

	size_t frst_hyphen = line.find('-');
	size_t scnd_hyphen = line.find('-', frst_hyphen);
	if (frst_hyphen == std::string::npos || scnd_hyphen == std::string::npos)
		throw WrongFormat();
	size_t separator = line.find(',');
	if (separator == std::string::npos){
		separator = line.find('|');
		if (separator == std::string::npos)
			throw WrongFormat();	
	}
	std::string year = line.substr(0, frst_hyphen);
	std::string month = line.substr(frst_hyphen + 1, scnd_hyphen);
	std::string day = line.substr(scnd_hyphen + 1, line.size());
	int DaysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 month = TrimZero(month);
 day = TrimZero(day);
	if (std::atoi(month.c_str()) == 2 && isLeapYear(std::atoi(year.c_str())))
		DaysInMonths[1] = 29;
	std::cout << std::atoi(year.c_str()) << std::endl;
	if (std::atoi(year.c_str()) < 2009 || std::atoi(year.c_str()) > 2022)
		throw WrongFormat();

	if (std::atoi(month.c_str()) < 1 || std::atoi(year.c_str()) > 12)
		throw WrongFormat();
	// if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > DaysInMonths[std::atoi(month.c_str())])
	// 	throw WrongFormat();	
}

void BitcoinData::CreateMap(const char * filename, BitcoinData data){
	std::filebuf fb;
	if (fb.open(filename, std::ios::in)){
		std::istream is(&fb);
		std::string line;
		std::getline(is, line);
		while(std::getline(is, line)){
			try{
				CheckFormat(line);
			}
			catch(std::exception &e){
				std::cout << e.what() << std::endl;
				exit (1);
			}
			std::string date = line.substr(0, (line.find(',') - 1));
			std::string	strvalue = line.substr((line.find(',') + 1), line.size()); 
			int value = std::atoi(strvalue.c_str());
			data.value[date] = value;
		}
	}
	else {
		fb.close();
		throw FileCantBeOpen();
	}
	fb.close();
}

const char *BitcoinData::FileCantBeOpen::what() const throw(){
	return "Can't open file";
}

const char *BitcoinData::WrongFormat::what() const throw(){
	return "Wrong Format";
}