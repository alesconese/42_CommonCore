#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Shrubbery Creation Form * * * * *" << std::endl;
		try
		{
			Intern	i1;
			AForm *shrub1 = i1.makeForm("Shrubbery Creation", "garden");
			std::cout << "* " << *shrub1 << std::endl;
			delete shrub1;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n* * * * * TEST 2: Robotomy Request Form * * * * *" << std::endl;
		try
		{
			Intern	i1;
			AForm *robo1 = i1.makeForm("Robotomy Request", "Alexa");
			std::cout << "* " << *robo1 << std::endl;
			delete robo1;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n* * * * * TEST 3: Presidential Pardon Form * * * * *" << std::endl;
		try
		{
			Intern	i1;
			AForm *presi1 = i1.makeForm("Presidential Pardon", "P.Demon");
			std::cout << "* " << *presi1 << std::endl;
			delete presi1;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n* * * * * TEST 4: Invalid Form * * * * *" << std::endl;
		try
		{
			Intern	i1;
			AForm *form1 = i1.makeForm("Shrubbery Pardon", "Esbarzers");
			std::cout << "* " << *form1 << std::endl;
			delete form1;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << std::endl;
		}
	}
}
