#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();


	//This is just wrong
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;

	wrong->makeSound();
	wrongcat->makeSound();
	
//CLEANUP
	delete meta;
	delete j;
	delete i;

	delete wrong;
	delete wrongcat;

	return 0;
}



// int main ()
// {
// 	const Animal* a = new Dog();
// 	a->makeSound();
// 	const Animal* b = new Cat();
// 	b->makeSound();

// 	delete a;
// 	delete b;
// 	return 0;
// }