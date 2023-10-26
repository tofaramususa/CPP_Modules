#include "ClapTrap.hpp"

int main(void)
{
	std::string input("BAD_GUY");
	std::string input_2("GOOD_GUY");
	ClapTrap a;
	ClapTrap b(input_2);

	a.SetDamagePoints(5);
	a.attack(input);
	std::cout << "a hit points: " << a.GetHitPoints() << std::endl;
	a.attack(input);
	std::cout << "a hit points: " << a.GetHitPoints() << std::endl;
	a.attack(input);
	a.takeDamage(20);
	b.SetDamagePoints(20);
	b.attack(input);
	ClapTrap c(b);
	std::cout << "C Hit Points:" << c.GetHitPoints() << std::endl;
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	std::cout << "B Hit Points: " << b.GetHitPoints() << std::endl;
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
}