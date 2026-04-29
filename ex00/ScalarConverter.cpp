#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>

/*
123123
-1231
11872628736487236487623 (int max)
-11872628736487236487623 (int min)
a23423
sa324
+-34
-3
0000
+0
-0
.0234
1.232
a.1
0.a
""
\n2
\t
f
1.2f
1f
0f
ff
-4f
-3.f4
-3.0f4
*/
void	char_case(const char &c);
void	float_case(long &lval);

void	ScalarConverter::convert(const std::string &str)
{
	long	lval;
	char	*end;

	end = nullptr;

	// char case
	if (str.size() == 1 && std::isalpha(str[0]))
		return (char_case (str[0]));

	// conver to double
	lval = std::strtod (str.c_str(), &end);

	// float case
	if (*end == 'f' && *(end + 1) == 0)
		return (float_case(lval));

	// does it have a . in it >> double
	//if ()


	// else would be int 

	// else naan no bla bla bal 
	
	// else unconvertable


	// if (*end == 0)
		// it s a number



	std::cout	<< "val is: "	<< lval
				<< std::endl;
	return ;
}

void	char_case(const char &c)
{
	(void)c;
	return ;
}

void	float_case(long &lval)
{
	std::cout	<< "floaty" << static_cast<float>(lval) << std::endl;
	return ;
}