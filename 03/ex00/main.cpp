#include "ClapTrap.hpp"

int main(void)
{
	std::string input("BAD GUY");
	std::string input_2("GOOD GUY");
	ClapTrap a;
	ClapTrap b(input_2);

	std::cout << "a Hit points: " << a.GetHitPoints() << std::endl;
	std::cout << "a has Energy points: " << a.GetEnergyPoints() << std::endl;
	a.attack(input);
	a.SetDamagePoints(5);
	std::cout << "a Hit points: " << a.GetHitPoints() << std::endl;
	std::cout << "a has Energy points: " << a.GetEnergyPoints() << std::endl;
	a.attack(input);
	a.attack(input);
	std::cout << "a Hit points: " << a.GetHitPoints() << std::endl;
	std::cout << "a has Energy points: " << a.GetEnergyPoints() << std::endl;
	a.takeDamage(20);
	b.SetDamagePoints(20);
	b.attack(input);
	std::cout << "B Hit Points: " << b.GetHitPoints() << std::endl;
	std::cout << "B Energy Points: " << b.GetEnergyPoints() << std::endl;
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	std::cout << "B Hit Points: " << b.GetHitPoints() << std::endl;
	std::cout << "B Energy Points: " << b.GetEnergyPoints() << std::endl;
	ClapTrap c(b);
	std::cout << "C Hit Points: " << c.GetHitPoints() << std::endl;
	std::cout << "C Energy Points: " << c.GetEnergyPoints() << std::endl;
	c.beRepaired(10);
	c.beRepaired(10);
	std::cout << "C Hit Points: " << c.GetHitPoints() << std::endl;
	std::cout << "C Energy Points: " << c.GetEnergyPoints() << std::endl;
}
