/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:31:58 by lsouquie          #+#    #+#             */
/*   Updated: 2024/08/29 18:44:41 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits.h>

class BitcoinData {
	private :
		std::map<std::string, float> value;
		
	public :
		BitcoinData();
		BitcoinData(const BitcoinData& rhs);
		~BitcoinData();
		BitcoinData &operator=(const BitcoinData& rhs);
		void CreateMap(const char *filename, BitcoinData &data);
		void CheckFormat(std::string line);
		bool isLeapYear(int year);
		float GetValue(std::string date);
		void CheckDate(std::string date);
		void CheckValue(std::string value);

		class FileCantBeOpen : public std::exception{
			virtual const char* what() const throw();
		};

		class WrongFormat : public std::exception{
			virtual const char* what() const throw();
		};
		
		class NegativeNumber : public std::exception{
			virtual const char* what() const throw();
		};

		class AboveIntMax : public std::exception{
			virtual const char* what() const throw();
		};
};



#endif