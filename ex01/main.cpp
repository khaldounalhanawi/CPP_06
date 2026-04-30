/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:05:58 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/30 18:06:00 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	*myData = new Data();

	myData->first = 99;
	myData->second = 'c';

	uintptr_t temp = Serializer::serialize (myData);

	Data *restored = NULL;
	restored = Serializer::deserialize (temp);


	std::cout<< ">>>>>>>> Address check! <<<<<<"<< std::endl;
	std::cout<< myData << std::endl;
	std::cout<< restored << std::endl;

	std::cout<< ">>>>>>>> Values check! <<<<<<"<< std::endl;
	std::cout<< restored->first << std::endl;
	std::cout<< restored->second << std::endl;
	return (0);
}