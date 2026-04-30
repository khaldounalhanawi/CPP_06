#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cmath>

void	print_char(const char &c);
void	print_number(double &lval);
bool	handle_literals(const std::string &str);
bool	handle_double_edges(const double &doubleVal);

void	ScalarConverter::convert(const std::string &str)
{
	double	doubleVal;
	char	*end;

	end = nullptr;

	// char case
	if (str.size() == 1 && std::isalpha(str[0]))
		return (print_char (str[0]));

	// literals case
	if (handle_literals (str))
		return ;

	// conver to double
	doubleVal = std::strtod (str.c_str(), &end);
	if (handle_double_edges (doubleVal))
		return ;

	// numbers case
	if ((*end == 'f' && *(end + 1) == 0)
		|| *end == 0)
		return (print_number(doubleVal));

	// else error
	std::cout	<< "ERROR!" << std::endl;
	return ;
}

bool	handle_double_edges(const double &doubleVal)
{
	const static std::string	inf[2] = {"-inf", "inf"};
	
	if (std::isnan(doubleVal))
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: nanf"
					<< "\ndouble: nan"
					<< std::endl;
		return (true);
	}
	if (std::isinf(doubleVal))
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: "	<< inf[(doubleVal > 0)]
									<< "f"
					<< "\ndouble: "	<< inf[(doubleVal > 0)]
					<< std::endl;
		return (true);
	}
	return (false);
}

bool	handle_literals(const std::string &str)
{
	static const std::string	f_options[4] = {"-inff", "+inff", "inff", "nanf"};
	static const std::string	d_options[4] = { "-inf", "+inf", "inf", "nan"};

	for (int k = 0;k < 4; k++)
	{
		if (str == f_options[k] || str == d_options[k])
		{
			std::cout	<< "char: impossible"
						<< "\nint: impossible"
						<< "\nfloat: "	<< f_options[k]
						<< "\ndouble: "	<< d_options[k]
						<< std::endl;
			return (true);
		}
	}
	return (false);
}

void	print_char(const char &c)
{
	std::cout	<< "char: "			<< c
				<< "\nint: "		<< static_cast<int>(c) 
									<< std::fixed
				<< "\nfloat: "		<< std::setprecision(1)
									<< static_cast<float>(c)
									<< "f"
				<< "\ndouble: "		<< std::setprecision(1)
									<< static_cast<double>(c)
				<< std::endl;
	return ;
}

void	print_number(double &doubleVal)
{
	if (doubleVal > std::numeric_limits<float>::max()
		|| doubleVal < -std::numeric_limits<float>::max())
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: impossible";
	}
	else if (doubleVal > std::numeric_limits<int>::max()
			|| doubleVal < -std::numeric_limits<int>::max())
	{
		std::cout	<< "char: impossible"
					<< "\nint: impossible"
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(doubleVal) << "f";
	}
	else if (static_cast<int>(doubleVal) <= 31
			|| static_cast<int>(doubleVal) > 126)
	{
		std::cout	<< "char: Non displayable"
					<< "\nint: "	<< static_cast<int>(doubleVal)
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(doubleVal) << "f";
	}
	else
	{
		std::cout	<< "char: "		<< static_cast<char>(doubleVal)
					<< "\nint: "	<< static_cast<int>(doubleVal)
					<< "\nfloat: "	<< std::fixed
									<< std::setprecision(1)
									<< static_cast<float>(doubleVal) << "f";
	}

	std::cout	<< "\ndouble: "	<< std::fixed
								<< std::setprecision(1)
								<< static_cast<double>(doubleVal)
				<< std::endl;
	return ;
}
