#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	{
		std::string input("test");
		DiamondTrap a(input);
		a.whoAmI();
		std::cout << a << std::endl;
		a.attack(input);
		std::cout << a << std::endl;
		a.whoAmI();
		DiamondTrap b(a); //something wrong with copy constructor
		b.whoAmI();
		b.highFivesGuys();
        b.guardGate();

	}
	// {
	// 	std::string input("BAD GUY");
	// 	std::string input_2("GOOD GUY");
	// 	FragTrap a(input_2);

	// 	std::cout << "a " << a.GetName() << " has hit points " << a.GetHitPoints() << std::endl;
	// 	a.attack(input);
	// 	a.attack(input);
	// 	a.SetDamagePoints(60);
	// 	a.attack(input);
	// 	a.attack(input);
	// 	std::cout << "a " << a.GetName() << " has hit points " << a.GetHitPoints() << std::endl;
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	std::cout << "a " << a.GetName() << " has hit points " << a.GetHitPoints() << std::endl;
	// 	a.highFivesGuys();
	// }
	// {
	// 	std::string input("BAD GUY");
	// 	std::string input_2("GOOD GUY");
	// 	ScavTrap a(input_2);

	// 	std::cout << "a " << a.GetName() << " has hit points " << a.GetHitPoints() << std::endl;
	// 	a.attack(input);
	// 	a.attack(input);
	// 	a.SetDamagePoints(60);
	// 	a.attack(input);
	// 	a.attack(input);
	// 	std::cout << "a " << a.GetName() << " has hit points " << a.GetHitPoints() << std::endl;
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	a.beRepaired(10);
	// 	std::cout << "a " << a.GetName() << " has hit points " << a.GetHitPoints() << std::endl;
	// 	a.guardGate();
	// }

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