/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:42:57 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 23:00:13 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "/// Unique Brain test" << std::endl;
	Dog a;
	Dog b;
	a.getBrain()->addIdea("Food");
	std::cout << "Brain a[0]:" << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "Brain b[0]:" << b.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "/// a = b case" << std::endl;
	b = a;
	a.getBrain()->addIdea("AfterCopyA");
	b.getBrain()->addIdea("AfterCopyB");
	std::cout << "Brain a[0]:" << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "Brain b[0]:" << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "Brain a[1]:" << a.getBrain()->getIdea(1) << std::endl;
	std::cout << "Brain b[1]:" << b.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	std::cout << "/// Delete AAnimal test" << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	j->makeSound();
	i->makeSound();
	delete j;
	delete i;

	std::cout << "\n/// AAnimal Array test" << std::endl;

	AAnimal* arr[10];

	int n = 0;
	while(n < 10)
	{
		if (n < 5)
			arr[n] = new Dog();
		else if (n >= 5)
			arr[n] = new Cat();
		n++;
	}

	for (int j = 0; j < 10; j++)
	{
		delete arr[j];
	}
	std::cout << "\n/// Armageddon: stack cleanup" << std::endl;
	
	// Won't let you instantiate AAnimal because its an abstract class -
	// thanks to having a pure virtual function (=0).
	
	// new AAnimal();
	// AAnimal a;
	
	return 0;
}