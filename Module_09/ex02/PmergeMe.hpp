/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:57:54 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 16:57:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>

template<typename Container>
struct Storage {
	Container sublist;
	int link;
};

template<typename Container>
class PmergeMe{
	private :
		Container _data;
		size_t _sublist_size;
		size_t _prev_sublist_size;
		size_t _unsortedListSize;
		typename Container::iterator _last;
		size_t nb_elements;
		typename Container::iterator _checkEnd;
		Container _oddNumbers;
		int allow;
		std::string list;

		PmergeMe();
		void Init(char **av);
		void MergeSublist();
		void CreateSublist();
		void ft_swap(typename Container::iterator first, typename Container::iterator last);
		void SortElement();
		void JacobsthalLoop(Storage<Container> *unsortedList);
		void JacosthalInsert(typename Container::iterator first, typename Container::iterator second, size_t index, Storage<Container> *unsortedList);
		void CheckOtherSide(Storage<Container> *unsortedList, size_t index, int nb);

	public:

		PmergeMe(char **av);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe& rhs);
		~PmergeMe();
		void FordJonshonAlgo();
		void PrintList();
		size_t UnstortedListCalcul();
		bool is_sorted(size_t sizeElement);
		Container GetData() const;
		std::string GetList() const;

};

template<typename Iterator>
bool ft_is_sorted(Iterator first, Iterator last);

#endif