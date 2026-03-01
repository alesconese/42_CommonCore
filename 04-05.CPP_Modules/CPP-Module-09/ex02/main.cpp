#include "PMergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "(!) ERROR: Not enough arguments.\n";
		return 1;
	}
	
	try
	{
		PMergeMe::FJ(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "(!) ERROR: " << e.what() << '\n';
	}

	return 0;
}
