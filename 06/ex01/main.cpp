#include <stdint.h>
#include "Serializer.hpp"


int main()
{
	Data *Person = new Data;
	Person->name = "Tofara";

	uintptr_t secondName = Serializer::serialize(Person);

	Data *secondPerson = Serializer::deserialize(secondName);
	delete Person;

	return 0;
}