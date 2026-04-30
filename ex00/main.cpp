/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:07:32 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/30 17:07:33 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout	<< "Argument count error, hint: this program takes 1 arguments!"
					<< std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}
