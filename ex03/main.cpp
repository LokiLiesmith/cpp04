#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
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
	std::cout << "\n//Materia Clone test" << std::endl;
	std::cout << "i-type: " << i->getType() << std::endl;
	std::cout << "c-type: " << c->getType() << std::endl;
	AMateria* i_clone = i->clone();
	AMateria* c_clone = c->clone();
	std::cout << "iclone-type: " << i_clone->getType() << std::endl;
	std::cout << "cclone-type: " << c_clone->getType() << std::endl;
	
	//use, equip, unequip
	std::cout << "\n//The Ice bolt incident" << std::endl;
	Character tony("Tony");
	Character frankie("Frankie");
	tony.equip(i);
	tony.use(0, frankie);
	tony.unequip(0);
	tony.equip(c);
	tony.use(0, frankie);

	//Character copy
	std::cout << "\n//Character Copy" << std::endl; 
	Character copy(tony);
	copy.use(0, tony);
	std::cout << "\n//Character Assignment" << std::endl; 
	Character assigned("Assigned");
	assigned = tony;
	assigned.use(0, tony);

	
	//PROVIDED TEST
	std::cout << "\n//PROVIDED MATERIASOURCE TEST" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
			
	std::cout << "\n//Armageddon" << std::endl;
	delete i_clone;
	delete c_clone;

	return 0;
}
