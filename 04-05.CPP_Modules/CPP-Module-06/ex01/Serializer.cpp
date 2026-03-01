#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "* Serializer default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "* Serializer destructor called: " << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
	std::cout << "* Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer	&Serializer::operator=(Serializer const &src)
{
	std::cout << "* Serializer copy assignment constructor called" << std::endl;
	(void)src;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
