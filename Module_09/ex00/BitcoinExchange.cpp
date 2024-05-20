/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:05:01 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/20 18:53:01 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinData::BitcoinData() {
	
}

BitcoinData::~BitcoinData() {}

// BitcoinData::BitcoinData(const BitcoinData& rhs) {}

// BitcoinData& BitcoinData::operator=(const BitcoinData&rhs){
	
// }

float BitcoinData::GetValue(std::string date){
    if(this->value.count(date) > 0)
      return value.at(date);
    return ((--value.lower_bound(date))->second);
}

bool BitcoinData::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinData::CheckValue(std::string value){
	if (value[0] == '-')
		throw NegativeNumber();
	std::string trye = value;
	if (strtol(value.c_str(), NULL, 10) > 2147483647)
		throw AboveIntMax();
	for (int i = 0; value[i]; i++)
	{
		if (value[i] == '\r')
			value[i] = '\0';
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != '\0'){
			throw WrongFormat();
		}
	}
}

void BitcoinData::CheckDate(std::string date){
	
	size_t frst_hyphen = date.find('-');
	size_t scnd_hyphen = date.find('-', frst_hyphen + 1);
	if (frst_hyphen == std::string::npos || scnd_hyphen == std::string::npos)
		throw WrongFormat();
	std::string syear = date.substr(0, frst_hyphen);
	std::string smonth = date.substr(frst_hyphen + 1, scnd_hyphen - 5);
	std::string sday = date.substr(scnd_hyphen + 1, date.size());
	int year = (strtol(syear.c_str(), NULL, 10));
	int month = (strtol(smonth.c_str(), NULL, 10));
	int day = (strtol(sday.c_str(), NULL, 10));
	if (year < 2009 || year > 2022)
		throw WrongFormat();
	if (month < 1 || month > 12)
		throw WrongFormat();
	if (month == 2){
		if (isLeapYear(year) && day > 29)
			throw WrongFormat();
		else if(!isLeapYear(year) && day > 28)
			throw WrongFormat();
	}
	if ((day < 1 || day > 31) || (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))) 
		throw WrongFormat();
}

void BitcoinData::CheckFormat(std::string line){
	
	size_t frst_hyphen = line.find('-');
	size_t scnd_hyphen = line.find('-', frst_hyphen);
	if (frst_hyphen == std::string::npos || scnd_hyphen == std::string::npos
	|| line.find_first_not_of("0123456789,-.") != std::string::npos)
		throw WrongFormat();
	if (line.find(',') == std::string::npos)
			throw WrongFormat();
}

void BitcoinData::CreateMap(const char * filename, BitcoinData &data){
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
				std::cerr << "Error: " << e.what() << line << std::endl;
				return ;
			}
			std::string date = line.substr(0, (line.find(',')));
			std::string	strvalue = line.substr((line.find(',') + 1), line.size());
			try{
				CheckValue(strvalue);
				CheckDate(date);
			}
			catch(std::exception &e){
				std::cerr << "Error: " << e.what() << line << std::endl;
				return ;
			}
			float value = strtof(strvalue.c_str(), NULL);
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
	return "Bad input => ";
}

const char *BitcoinData::NegativeNumber::what() const throw(){
	return "Not a positive number =>";
}

const char *BitcoinData::AboveIntMax::what() const throw(){
	return "Too large number => ";
}