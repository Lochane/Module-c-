/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:30:49 by marvin            #+#    #+#             */
/*   Updated: 2024/05/23 17:30:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename Container>
bool PmergeMe<Container>::is_sorted(size_t sizeElement)
{
    typename Container::iterator it = _data.begin();

    typename Container::iterator prev = it;
    advance(it, sizeElement + (sizeElement - 1));
    advance(prev, sizeElement-1);
    while (1)
    {
        if (*prev > *it)
        {
            return false;
        }
        if ((size_t)std::distance(it, _data.end()) <= sizeElement)
            break ;
        advance(it, sizeElement);
        advance(prev, sizeElement);
    }
    return true;
}

int main(int ac, char **av){
	if (ac < 3){
		std::cerr << "You need minimum 2 arguments" << std::endl;
		return 0;
	}
	

	try {
		PmergeMe<std::deque<int> > vector(av);
		vector.FordJonshonAlgo();
		std::cout<<"is sorted : "<< vector.is_sorted(1)<<std::endl;
	}
	catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}