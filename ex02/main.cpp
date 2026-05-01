#include "Base.hpp"
#include "ABC.hpp"
#include <iostream>

Base	*generate(void)
{
	return (new B);
}

void	identify(Base* p)
{
	if (!p)
		return ;
	
	A	*attempt1 = dynamic_cast<A*>(p);
	if (attempt1)
	{
		std::cout<<	"Pointer is of type A" << std::endl;
		return ;
	}

	B	*attempt2 = dynamic_cast<B*>(p);
	if (attempt2)
	{
		std::cout<<	"Pointer is of type B" << std::endl;
		return ;
	}

	C	*attempt3 = dynamic_cast<C*>(p);
	if (attempt3)
	{
		std::cout<<	"Pointer is of type C" << std::endl;
		return ;
	}
}

void	identify(Base& p)
{
	try
	{
		A &attempt1 = dynamic_cast<A&>(p);
		std::cout<<	"Pointer is of type A" << std::endl;
		(void)attempt1;
		return ;
	}
	catch (...){};

	try
	{
		B &attempt2 =dynamic_cast<B&>(p);
		std::cout<<	"Pointer is of type B" << std::endl;
		(void)attempt2;
		return ;
	}
	catch (...){};

	try
	{
		C &attempt3 =dynamic_cast<C&>(p);
		std::cout<<	"Pointer is of type C" << std::endl;
		(void)attempt3;
		return ;
	}
	catch (...){};
	return ;
}

int	main()
{
	std::cout<<	"*** Random generation & Identifier tests ***" << std::endl;
	
	for (int i = 0 ; i < 5; i++)
	{
		Base *p = generate();
		identify (p);
	}

	std::cout<<	"*** Referance Identifier tests ***" << std::endl;

	{
		C item;
		C &ref = item;
		identify (ref);
	}

	{
		A item;
		A &ref = item;
		identify (ref);
	}

	{
		B item;
		B &ref = item;
		identify (ref);
	}
	return (0);
}
