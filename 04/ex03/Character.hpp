#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class Character : public ICharacter
{
	private:
	std::string name;
	AMateria *inventory[4];
	AMateria *oldMateria[4];
	int oldestMateriaIndex;

	public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter &target); 
	void storeMateria(AMateria *m);
};

#endif