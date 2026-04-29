#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	public:
		static void	convert(const std::string &str);
};

#endif



/*
Write a class ScalarConverter:
1- that will contain only one static method "convert":
	< that will take as a parameter a string representation of a C++ literal in its most common form 
	> and output its value in the following series of scalar types:
		• char
		• int
		• float
		• double

As this class doesn’t need to store anything at all, it must not be instantiable by users.

** Except for char parameters, only the decimal notation will be used. // ????

   Examples of char literals: ’c’, ’a’, ...

** To make things simple, please note that non-displayable characters shouldn’t be used as
inputs.

** If a conversion to char is not displayable, print an informative message.

   Examples of int literals: 0, -42, 42...
   Examples of float literals: 0.0f, -4.2f, 4.2f...

** You have to handle these pseudo-literals as well (you know, for science): -inff, +inff, and nanf. // ????


Write a program to test that your class works as expected:

-> You have to first detect the type of the literal passed as a parameter,
-> convert it from string to its actual type,
-> then convert it explicitly to the three other data types.
-> Lastly,display the results as shown below.

** If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible.

** Include any header you need in order to handle numeric limits and special values.

*/