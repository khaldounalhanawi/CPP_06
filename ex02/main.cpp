#include "Base.hpp"
#include "ABC.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	int	dice;
	int	f1;
	int	f2;

	f1 = std::rand() % 2;
	f2 = std::rand() % 2;

	dice = f1 + f2;
	switch (dice)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
	};
	return (NULL);
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
		std::cout<<	"Type of the object referenced by p: A" << std::endl;
		(void) attempt1;
		return ;
	}
	catch (...){};

	try
	{
		B &attempt2 = dynamic_cast<B&>(p);
		std::cout<<	"Type of the object referenced by p: B" << std::endl;
		(void) attempt2;
		return ;
	}
	catch (...){};

	try
	{
		C &attempt3 = dynamic_cast<C&>(p);
		std::cout<<	"Type of the object referenced by p: C" << std::endl;
		(void) attempt3;
		return ;
	}
	catch (...){};
	return ;
}

int	main()
{
	std::srand(std::time(0));

	std::cout<<	"*** Random generation & Identifier tests ***" << std::endl;
	
	for (int i = 0 ; i < 5; i++)
	{
		Base *p = generate();
		identify (p);
		delete (p);
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
