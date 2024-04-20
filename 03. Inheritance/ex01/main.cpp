#include "ScavTrap.hpp"

int main(void)
{
	{
		std::string input("BAD GUY");
		std::string input_2("GOOD GUY");
		ScavTrap a(input_2);

		std::cout << "a " << a.GetName() << " has Hit points " << a.GetHitPoints() << std::endl;
		std::cout << "a " << a.GetName() << " has Energy points " << a.GetEnergyPoints() << std::endl;
		a.attack(input);
		a.attack(input);
		a.SetDamagePoints(60);
		a.attack(input);
		a.attack(input);
		std::cout << "a " << a.GetName() << " has Hit points " << a.GetHitPoints() << std::endl;
		std::cout << "a " << a.GetName() << " has Energy points " << a.GetEnergyPoints() << std::endl;
		a.beRepaired(10);
		a.beRepaired(10);
		a.beRepaired(10);
		a.beRepaired(10);
		a.beRepaired(10);
		std::cout << "a " << a.GetName() << " has Hit points " << a.GetHitPoints() << std::endl;
		std::cout << "a " << a.GetName() << " has Energy points " << a.GetEnergyPoints() << std::endl;
		a.guardGate();
	}
	// {
	// 	std::string input("BAD GUY");
	// 	std::string input_2("GOOD GUY");
	// 	ClapTrap a;
	// 	ClapTrap b(input_2);

	// 	a.SetDamagePoints(5);
	// 	a.attack(input);
	// 	std::cout << "a hit points: " << a.GetHitPoints() << std::endl;
	// 	a.attack(input);
	// 	std::cout << "a hit points: " << a.GetHitPoints() << std::endl;
	// 	a.attack(input);
	// 	a.takeDamage(20);
	// 	b.SetDamagePoints(20);
	// 	b.attack(input);
	// 	ClapTrap c(b);
	// 	std::cout << "C Hit Points:" << c.GetHitPoints() << std::endl;
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	std::cout << "B Hit Points: " << b.GetHitPoints() << std::endl;
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// 	b.beRepaired(10);
	// }
}