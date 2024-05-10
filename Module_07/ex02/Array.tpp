/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:59:21 by marvin            #+#    #+#             */
/*   Updated: 2024/05/09 11:59:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : _a(new T[0]), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n) : _a(new T[n]), _size(n){}

template<typename T>
Array<T>::Array(const Array<T>& rhs) : _a(new T[rhs.size()]), _size(rhs.size()){
	*this = rhs;
}

template<typename T>
Array<T>::~Array() {
	delete []_a;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs){
	
	delete [] _a;
	_a = new T[rhs.size()];
	_size = rhs._size;
	for (unsigned int i = 0; i < _size; i++)
		_a[i] = rhs._a[i];
	return *this;
}

template<typename T>
unsigned int Array<T>::size() const{
	return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int i){
	if (i >= _size)
		throw OutOfRange();
	return _a[i];
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const{
	if (i >= _size)
		throw OutOfRange();
	return _a[i];
}

template<typename T>
const char *Array<T>::OutOfRange::what() const throw() {
	return "Index out of range";
}

#endif