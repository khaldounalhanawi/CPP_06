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
/*

Write a program to test that your class works as expected:

-> You have to first detect the type of the literal passed as a parameter,
-> convert it from string to its actual type,
-> then convert it explicitly to the three other data types.
-> Lastly,display the results as shown below.

** If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible.

** Include any header you need in order to handle numeric limits and special values.

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

*/
