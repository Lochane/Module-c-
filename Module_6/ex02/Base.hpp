/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:12:58 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 11:12:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Base{
	public:
	 	virtual ~Base() {};
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif