#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "--- Testing arithmetic operators ---" << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << "--- Testing pre-increment operators ---" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "--- Testing comparison operators ---" << std::endl;
	print_boolean(a < b);
	print_boolean(a > b);
	print_boolean(a >= b);
	print_boolean(a <= b);
	print_boolean(a == b);
	print_boolean(a != b);
	return 0;
}
