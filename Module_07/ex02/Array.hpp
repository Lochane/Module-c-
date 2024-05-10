/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:34:28 by marvin            #+#    #+#             */
/*   Updated: 2024/05/09 11:34:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h> 

template<typename T>
class Array {
	private:
		T* _a;
		unsigned int _size;
	
	public :
		Array();
		Array(unsigned int n);
		Array(const Array<T>& rhs);
		~Array();
		Array<T>& operator=(const Array<T>& rhs);

		unsigned int size() const;
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const ;

		class OutOfRange : public std::exception{
			virtual const char * what() const throw();
		};
};



#include "Array.tpp"

#endif