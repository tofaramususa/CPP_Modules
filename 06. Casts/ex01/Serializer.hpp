#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

struct	Data
{
	std::string name;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t ptr);
	private:
		Serializer();
};

#endif