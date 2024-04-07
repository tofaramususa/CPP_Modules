#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "methods.cpp"
#include <cstdlib>
#include <iostream>

Base	*generate(void)
{
	srand(time(NULL));  // generating a random value
	int i = rand() % 3; // rand of 3 numbers
	switch (i)
	{
	case 0:
		std::cout << "A generated" << std::endl;
		return (new A);
	case 1:
		std::cout << "B generated" << std::endl;
		return (new B);
	case 2:
		std::cout << "C generated" << std::endl;
		return (new C);
	default:
		std::cout << "Could not generate new class" << std::endl;
		return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "Class pointer is A" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "Class pointer is B" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "Class pointer is C" << std::endl;
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Class reference is A" << std::endl;
		(void)a;
		return ;
	}
	catch (...)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Class reference is B" << std::endl;
		(void)b;
		return ;
	}
	catch (...)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Class reference is C" << std::endl;
		(void)c;
		return ;
	}
	catch (...)
	{
	}
}

int main()
{

}