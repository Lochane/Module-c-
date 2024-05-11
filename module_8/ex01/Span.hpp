/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:07:02 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/11 18:17:11 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		Span();
		size_t size;
		std::vector<int> data;
		
	public:
		Span(size_t N);
		Span(const Span& rhs);
		~Span();
		Span &operator=(const Span& rhs);

		void addNumber(int n);
		void addRandNumbers(size_t N);
		int shortestSpan();
		int longestSpan();
		
		class FullStorage : public std::exception{
			virtual const char * what() const throw();
		};
		
		class CantFoundDist : public std::exception{
			virtual const char * what() const throw();
		};
};

#endif