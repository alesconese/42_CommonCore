#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "* Base destructor called" << std::endl;
}

Base	*generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	switch (std::rand() % 3)
	{
		case 0:
			return (std::cout << "* Generated A" << std::endl, new A());
		case 1:
			return (std::cout << "* Generated B" << std::endl, new B());
		case 2:
			return (std::cout << "* Generated C" << std::endl, new C());
		default:
			break;
	}
	std::cout << "(!) ERROR: Unexpected rand() generated" << std::endl;
	return NULL;
}

void	identify(Base *p)
{
	if (p == NULL)
		std::cout << "* Pointer is NULL" << std::endl;
	else if (dynamic_cast<A *>(p))
		std::cout << "* Pointer is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "* Pointer is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "* Pointer is C" << std::endl;
	else
		std::cout << "(!) ERROR: Unexpected pointer type" << std::endl;
}

void	identify(Base &p)
{
	try 
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "* Reference is A" << std::endl;
		return;
	}
	catch (const std::exception &e) { }
	try 
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "* Reference is B" << std::endl;
		return;
	}
	catch (const std::exception &e) { }
	try 
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "* Reference is C" << std::endl;
		return;
	}
	catch (const std::exception &e) { }
	std::cout << "(!) ERROR: Unexpected reference type" << std::endl;
}
