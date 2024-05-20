/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:30:15 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/20 19:14:55 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	
	(void)av;
	if (ac != 2){
		std::cerr << "Programme need 1 argument" << std::endl;
		return 1;
	}
	BitcoinData data;
	
	data.CreateMap("data.csv", data); //TODO mettre try & catch
	std::filebuf fb;
	if (fb.open(av[1], std::ios::in)){
		std::istream is(&fb);
		std::string line;
		std::getline(is, line);
		while(std::getline(is, line)){
			if (line.find('|') == std::string::npos)
				std::cerr << "Error: Wrong format => "<< line << std::endl;
			else{
				std::string date = line.substr(0, (line.find('|') - 1));
				std::string value = line.substr((line.find('|') + 2), line.size());
				try{
					data.CheckDate(date);
					data.CheckValue(value);
					std::cout << date << " => ";
					std::cout << (strtof(value.c_str(), NULL) * data.GetValue(date)) << std::endl;
				}
				catch(std::exception &e){
					std::cerr << "Error: "<<e.what() << date <<std::endl;
				}
			}
		}
	}
	else 
		std::cerr << "Error: could not open file" << std::endl;
}