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


// int main(int ac, char **av) {
//     if (ac < 3) {
//         std::cerr << "You need minimum 2 arguments" << std::endl;
//         return 0;
//     }

//     try {
//         PmergeMe<std::deque<int> > deque(av);

//         std::clock_t start = std::clock();  // Début du chronométrage
//         deque.FordJonshonAlgo();
//         std::clock_t end = std::clock();    // Fin du chronométrage

//         double duration = (end - start) / (double) CLOCKS_PER_SEC;  // Calcul de la durée en secondes
//         std::cout << "Time taken for std::deque: " << duration << " seconds" << std::endl;

//         std::cout << "is sorted: " << deque.is_sorted(1) << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     try {
//         PmergeMe<std::vector<int> > vector(av);

//         std::clock_t start = std::clock();  // Début du chronométrage
//         vector.FordJonshonAlgo();
//         std::clock_t end = std::clock();    // Fin du chronométrage

//         double duration = (end - start) / (double) CLOCKS_PER_SEC;  // Calcul de la durée en secondes
//         std::cout << "Time taken for std::vector: " << duration << " seconds" << std::endl;

//         std::cout << "is sorted: " << vector.is_sorted(1) << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
// }

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Not enougth args";
		return (1);
	}
	try
	{
		PmergeMe<std::deque<int> > deque(av);
        PmergeMe<std::vector<int> > vector(av);
        std::string list = deque.GetList();
        std::cout << "Before = ";
        deque.PrintList();

		clock_t	start= clock();
        deque.FordJonshonAlgo();
		clock_t	end = clock();
		double	dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout <<std::endl;
		start = clock();
		vector.FordJonshonAlgo();
		end = clock();
		double	vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
        std::cout << "After = ";
        deque.PrintList(); 
		std::cout << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " <<vectorTime << " µs" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " <<dequeTime << " µs" << std::endl;
        std::cout <<"is sorted : " << vector.is_sorted(1) << std::endl;
	}
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return (0);
}
