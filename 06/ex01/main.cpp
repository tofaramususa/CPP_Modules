#include <stdint.h>
#include "Serializer.hpp"

int main()
{
	Data *Person = new Data;
	Person->name = "Tofara";

	uintptr_t secondName = Serializer::serialize(Person);
	std::cout << secondName << std::endl;
	Data *secondPerson = Serializer::deserialize(secondName);
	std::cout << secondPerson->name << std::endl;
	delete Person;

	return 0;
}