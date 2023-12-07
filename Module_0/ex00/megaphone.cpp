/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:02:31 by lsouquie          #+#    #+#             */
/*   Updated: 2023/11/27 18:04:17 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>


int main(int ac, char **argv)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
}