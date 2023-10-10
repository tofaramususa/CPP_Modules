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

	public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	std::string const & getName() const override;
	void equip(AMateria *m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter &target) override; 
};

#endif