#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>

typedef struct s_Data Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer () {};
};

#endif