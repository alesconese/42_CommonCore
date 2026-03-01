
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>
# include <iostream>

struct Data
{
	int			ID;
	std::string	name;
};

class Serializer
{
	private:
			Serializer();
			~Serializer();
			Serializer(Serializer const &src);
			Serializer &operator=(Serializer const &src);

	public:
			static uintptr_t	serialize(Data* ptr);
			static Data			*deserialize(uintptr_t raw);
};

#endif
