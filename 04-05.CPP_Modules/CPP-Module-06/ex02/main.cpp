#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	{
		std::cout << "* * * * * TEST 1: Passing nullptr * * * * *" << std::endl;
		Base	*b1 = NULL;

		identify(b1);
	}
	{
		std::cout << "\n\n* * * * * TEST 2: Generate & Identify * * * * *" << std::endl;
		Base	*b2;

		for (int i = 0; i < 10; i++)
		{
			b2 = generate();
			identify(b2);
			identify(*b2);
			delete b2;
		}
	}
	{
		std::cout << "\n\n* * * * * TEST 3: Wrong type * * * * *" << std::endl;
		class D : public Base { };
		
		Base	*b3 = new D();

		identify(b3);
		identify(*b3);
		delete b3;
	}

	return 0;
}
