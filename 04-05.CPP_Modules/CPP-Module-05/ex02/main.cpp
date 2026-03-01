#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Shrubbery Creation Form * * * * *" << std::endl;
		ShrubberyCreationForm shrub1("garden");
		{
			std::cout << "\n* * * TEST 1.1: Grade too low to sign * * *" << std::endl;
			Bureaucrat b1("Mike", 146);

			b1.signForm(shrub1);
		}
		{
			std::cout << "\n* * * TEST 1.2: Executing without signing * * *" << std::endl;
			Bureaucrat b2("Bob", 137);

			b2.executeForm(shrub1);
		}
		{
			std::cout << "\n* * * TEST 1.3: Grade too low to execute * * *" << std::endl;
			Bureaucrat b3("Jim", 138);

			b3.signForm(shrub1);
			b3.executeForm(shrub1);
		}
		{
			std::cout << "\n* * * TEST 1.4: Successful execution * * *" << std::endl;
			Bureaucrat b4("Bill", 137);

			b4.executeForm(shrub1);
		}
	}
	{
		std::cout << "\n\n* * * * * TEST 2: Robotomy Request Form * * * * *" << std::endl;
		RobotomyRequestForm robo1("Alexa");
		{
			std::cout << "\n* * * TEST 2.1: Grade too low to sign * * *" << std::endl;
			Bureaucrat b1("Mike", 73);

			b1.signForm(robo1);
		}
		{
			std::cout << "\n* * * TEST 2.2: Executing without signing * * *" << std::endl;
			Bureaucrat b2("Bob", 45);

			b2.executeForm(robo1);
		}
		{
			std::cout << "\n* * * TEST 2.3: Grade too low to execute * * *" << std::endl;
			Bureaucrat b3("Jim", 46);

			b3.signForm(robo1);
			b3.executeForm(robo1);
		}
		{
			std::cout << "\n* * * TEST 2.4: Successful execution * * *" << std::endl;
			Bureaucrat b4("Bill", 45);

			b4.executeForm(robo1);
		}
	}
	{
		std::cout << "\n\n* * * * * TEST 3: Presidential Pardon Form * * * * *" << std::endl;
		PresidentialPardonForm presi1("P.Demon");
		{
			std::cout << "\n* * * TEST 3.1: Grade too low to sign * * *" << std::endl;
			Bureaucrat b1("Mike", 26);

			b1.signForm(presi1);
		}
		{
			std::cout << "\n* * * TEST 3.2: Executing without signing * * *" << std::endl;
			Bureaucrat b2("Bob", 5);

			b2.executeForm(presi1);
		}
		{
			std::cout << "\n* * * TEST 3.3: Grade too low to execute * * *" << std::endl;
			Bureaucrat b3("Jim", 6);

			b3.signForm(presi1);
			b3.executeForm(presi1);
		}
		{
			std::cout << "\n* * * TEST 3.4: Successful execution * * *" << std::endl;
			Bureaucrat b4("Bill", 5);

			b4.executeForm(presi1);
		}
	}
}
