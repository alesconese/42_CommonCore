#include "Serializer.hpp"

int	main()
{
	Data 		initial = {1234, "Walter White"};
	uintptr_t	serialized = Serializer::serialize(&initial);
	Data 		*deserialized = Serializer::deserialize(serialized);

	std::cout << "* Initial data:" << std::endl;
	std::cout << "Data address: " << &initial << std::endl;
	std::cout << "ID: " << initial.ID << std::endl;
	std::cout << "name: " << initial.name << std::endl;

	std::cout << std::endl << "* Serialized data:" << std::endl;
	std::cout << "address: " << &serialized << std::endl;
	std::cout << "content: " << serialized << std::endl;

	std::cout << std::endl << "* Deserialized data:" << std::endl;
	std::cout << "Data address: " << &deserialized << std::endl;
	std::cout << "ID: " << deserialized->ID << std::endl;
	std::cout << "name: " << deserialized->name << std::endl;

	return 0;
}
