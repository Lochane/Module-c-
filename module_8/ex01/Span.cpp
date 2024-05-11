/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:32:20 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/11 19:35:04 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t N) : size(N), data(0){
}

Span::Span(const Span& rhs) : size(rhs.size), data(rhs.data){
	*this = rhs;
}

Span& Span::operator=(const Span& rhs) {
	this->size = rhs.size;
	this->data = rhs.data;
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int n){
	
	if (data.size() == size + 1)
		throw FullStorage();
	data.push_back(n);
}

void Span::addRandNumbers(size_t N){
	srand(time(NULL));
	for(size_t i = 0; i <= N; i++){
		addNumber(rand());
	}
}

int Span::shortestSpan(){
	if (data.empty() || size < 2)
		throw CantFoundDist();
	std::sort(data.begin(), data.end());
	int res = (data.at(1) - data.at(0)) - 1;
	for (std::vector<int>::iterator it = data.begin(); it != data.end() - 1; it++){
			if (std::abs(*(it + 1) - *it) < res)
				res = std::abs(*(it + 1) - *it);
	}
	return res;
}

int Span::longestSpan(){
	if (data.empty() || size < 2)
		throw CantFoundDist();
	int min = *std::min_element(data.begin(), data.end());
	int max = *std::max_element(data.begin(), data.end());
	return abs(max - min);	
}

const char* Span::FullStorage::what() const throw() {
	return "Storage is full";
}

const char* Span::CantFoundDist::what() const throw() {
	return "Span must have 2 elements";
}