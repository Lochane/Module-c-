/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:16:05 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 17:16:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename Iterator>
bool ft_is_sorted(Iterator first, Iterator last){
	if(first == last)
		return true;
	Iterator next = first;
	next++;
	while(next != last){
		if (*next < *first)
			return false;
		first = next;
		next++;
	}
	return true;
}

template<typename Container>
void PmergeMe<Container>::ft_swap(typename Container::iterator first, typename Container::iterator last){
	
		if (std::distance(first, last) == _sublist_size){
			for(size_t i = 0; i < _sublist_size; i++){
				std::swap(*first, *last);
				first--; last--;
			}
		}
}

template<typename Container>
size_t PmergeMe<Container>::UnstortedListCalcul(){
	size_t size;

	nb_elements =_data.size() / _sublist_size;
	_checkEnd = _data.begin();
	std::advance(_checkEnd, (nb_elements * _sublist_size));
	if (nb_elements % 2 == 0 && _data.size() % 2 == 0)
		size = (nb_elements / 2) - 1;
	else 
		size = (nb_elements / 2);
	if (size != 0 && std::distance(_checkEnd, _data.end()) < _sublist_size){
		_oddNumbers.insert(_oddNumbers.begin(), _checkEnd, _data.end());
		_checkEnd  = _data.erase(_checkEnd, _data.end());
	}
	if (_sublist_size == _oddNumbers.size() && allow == 0){
		size += 1;
		allow = 1;
	}
	return size;
}



template<typename Container>
void PmergeMe<Container>::SortElement(){
	_sublist_size /= 2;
	while (_sublist_size != 0){
		_unsortedListSize = UnstortedListCalcul();
		Storage<Container> *unsortedList = new Storage<Container>[_unsortedListSize];
		typename Container::iterator dataIt = _data.begin();
		std::advance(dataIt, (_sublist_size * 2));
		for (size_t i = 0; i < _unsortedListSize; i++){

			if (i == _unsortedListSize - 1 && allow == 1){
				unsortedList[i].sublist.insert(unsortedList[i].sublist.begin(), _oddNumbers.begin(), _oddNumbers.end());
				allow = 2;
			}
			if (std::distance(dataIt, _data.end()) >= _sublist_size){
				unsortedList[i].sublist.insert(unsortedList[i].sublist.begin(), dataIt, dataIt + _sublist_size);
				dataIt = _data.erase(dataIt, dataIt + _sublist_size);
				if (i == _unsortedListSize - 1)
					unsortedList[i].link = -1;
				else 
					unsortedList[i].link = *dataIt;
			}
			else {
				unsortedList[i].sublist.insert(unsortedList[i].sublist.begin(), dataIt, _data.end());
				dataIt = _data.erase(dataIt, _data.end());
				unsortedList[i].link = *dataIt;

			}
			std::advance(dataIt, _sublist_size);
		}
			JacobsthalLoop(unsortedList);
		_prev_sublist_size = _sublist_size;
		_sublist_size /= 2;
		delete[] unsortedList;

	}
	if (_data.size() % 2 == 0 && _data.at(0) == -1){
		_data.erase(_data.begin());
	}
}       

template<typename Container>
void PmergeMe<Container>::CheckOtherSide(Storage<Container> *unsortedList, size_t index, int nb){
	typename Container::iterator first = std::find(_data.begin(), _data.end(), unsortedList[index - 1].link);
	typename Container::iterator second = first + _sublist_size - 1;
	
	while (second != _data.end()){
		if (nb > *first && nb < *second){
			_data.insert(first + 1, unsortedList[index].sublist.begin(), unsortedList[index].sublist.end());
			return ;
		}
		if (second == _data.end() - 1){
			if (nb > *second)
				_data.insert(second + 1, unsortedList[index].sublist.begin(), unsortedList[index].sublist.end());
				return;
		
		}
	
	first++;
	}		
}


template<typename Container>
void PmergeMe<Container>::JacobsthalLoop(Storage<Container> *unsortedList){
	for (size_t i = _unsortedListSize; i > 0; i--){
		typename Container::iterator firstElement = _data.begin();
		typename Container::iterator secondElement = _data.begin();
		if (i == _unsortedListSize){
			std::advance(firstElement, (_data.size() - 1));
			secondElement = firstElement - _sublist_size;
		}
		else {
			firstElement = std::find(_data.begin(), _data.end(), unsortedList[i - 1].link) + _sublist_size - 1;
			secondElement = firstElement - _sublist_size;
		}
			JacosthalInsert(firstElement, secondElement, i, unsortedList);
	}
}

template<typename Container>
void PmergeMe<Container>::JacosthalInsert(typename Container::iterator first, typename Container::iterator second, size_t index, Storage<Container> *unsortedList){
	typename Container::iterator subEnd = unsortedList[index - 1].sublist.end() - 1;
	int nb = *subEnd;
	if (nb < *first && nb > *second){
		_data.insert(second + 1, unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());
		unsortedList[index - 1].sublist.erase(unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());
	}
	else {
		while (second != _data.begin()) {
			first = second;
			size_t distance = std::distance(_data.begin(), second);
			if (distance >= _sublist_size){
				std::advance(second, -static_cast<long>(_sublist_size));

			}
			else
				second = _data.begin();
			if (second == _data.begin()){
				if (nb > *second && nb < *first){
					if (unsortedList[index - 1].sublist.size() == 1)
						_data.insert(second + 1, unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());
					else{
						_data.insert(second, unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());

					}
					return;
				}
				else if (nb > *first){
					CheckOtherSide(unsortedList, index - 1, nb);
					return ;
				}
				else{
					_data.insert(second, unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());
					return;
				}
			}
			if (nb < *first && nb > *second){
					_data.insert(second + 1, unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());
				unsortedList[index - 1].sublist.erase(unsortedList[index - 1].sublist.begin(), unsortedList[index - 1].sublist.end());
				return;
			}
		}
	}
}

template<typename Container>
void PmergeMe<Container>::MergeSublist(){
	typename Container::iterator first = _data.begin();
	typename Container::iterator last =  _data.begin();
	std::advance(first, _sublist_size - 1);
	std::advance(last, _sublist_size + (_sublist_size - 1));

	while (_data.size() / _sublist_size > 1){
		for(size_t i = 0; i <= nb_elements / 2; i++){
			if(*first > *last)
				ft_swap(first, last);
		if (first + (_sublist_size * 2) >= _data.end())
			first = _data.end() - 1;
		else
			std::advance(first, _sublist_size * 2);
		if (last + (_sublist_size * 2) >= _data.end())
			last = _data.end() - 1;
		else
			std::advance(last,  _sublist_size * 2);
		}

		_sublist_size *= 2;
		if (nb_elements % 2 == 0){
			_prev_sublist_size = nb_elements;
			nb_elements /= 2;	
		}
		else {
			_prev_sublist_size = nb_elements;
			nb_elements /= 2;
			nb_elements += 1;

		}
		first = _data.begin();
		last = _data.begin();
		std::advance(first, _sublist_size - 1);
		std::advance(last, _sublist_size + (_sublist_size - 1));

	}
}

template<typename Container>
void PmergeMe<Container>::CreateSublist(){
	Container sorted_sublist;
	for (size_t i = 0; i < _data.size(); i += 2){
		Container sublist;
		sublist.push_back(_data[i]);
		if (i + 1 < _data.size())
			sublist.push_back(_data[i + 1]);
		else if (i + 1 >= _data.size() && _data.size() % 2 != 0)
				sublist.push_back(-1);
		std::sort(sublist.begin(), sublist.end());
		for(typename Container::iterator it = sublist.begin(); it < sublist.end(); it++)
			sorted_sublist.push_back(*it);
	}
	_data = sorted_sublist;
	nb_elements = _data.size() / 2;
}

template<typename Container>
void PmergeMe<Container>::FordJonshonAlgo(){
	CreateSublist();
	MergeSublist();
	SortElement();
	PrintSublist(_data);
}

template<typename Container>
void PmergeMe<Container>::PrintSublist(Container& sublists) {
 typename Container::iterator it;
    for (it = sublists.begin(); it != sublists.end(); ++it) {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

template<typename Container>
void PmergeMe<Container>::Init(char **av){
	std::string list;
	for (size_t i = 1; av[i]; i++){
		list += av[i];
		_data.push_back(atoi(av[i]));
	}
	if (list.find_first_not_of("0123456789") != std::string::npos)
		throw std::invalid_argument("Numbers only");
	if (ft_is_sorted(list.begin(), list.end()))
		throw std::invalid_argument("List already sort");
	for (typename Container::iterator it = _data.begin(); it < _data.end(); it++){
		for (typename Container::iterator it2 = it + 1; it2 < _data.end(); it2++){
			if (*it2 == *it){
					throw std::invalid_argument("Duplicates number");
			}
		}
	}
}

template<typename Container>
PmergeMe<Container>::PmergeMe(char **av){
	Init(av);
	_last = _data.begin() + 2;
	_sublist_size = 2;
	nb_elements = 0;
	allow = 0;
}

template<typename Container>
Container PmergeMe<Container>::GetData(){
	return _data;
}

template<typename Container>
PmergeMe<Container>::~PmergeMe(){};



template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;