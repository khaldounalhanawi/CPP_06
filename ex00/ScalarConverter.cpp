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

void	char_case(const char &c)
{
	(void)c;
	return ;
}

void	ScalarConverter::convert(const std::string &str)
{
	long	lval;
	char	*end;

	end = nullptr;
	if (str.size() == 1 && std::isalpha(str[0]))
		return (char_case (str[0]));


	lval = std::strtod (str.c_str(), &end);




	std::cout	<< "val is: "	<< lval
				<< std::endl;
	return ;
}

