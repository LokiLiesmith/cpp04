#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main(void)
{
	// Abstract class test - compiler wont let you assign a
	// AMateria a;


	//Construction
	std::cout << "Construction" << std::endl;
	AMateria* i = new Ice();
	AMateria* c = new Cure();
	
	//Clone Test
	std::cout << "\n//Clone test" << std::endl;
	std::cout << "i-type: " << i->getType() << std::endl;
	std::cout << "c-type: " << c->getType() << std::endl;
	AMateria* i_clone = i->clone();
	AMateria* c_clone = c->clone();
	std::cout << "iclone-type: " << i_clone->getType() << std::endl;
	std::cout << "cclone-type: " << c_clone->getType() << std::endl;
	
	//Swap Elements - assignment operator check
	std::cout << "\n//Swap elements" << std::endl;
	i = c;
	c = i_clone;
	std::cout << "new i-type: " << i->getType() << std::endl;
	std::cout << "new c-type: " << c->getType() << std::endl;
	





	return 0;
}