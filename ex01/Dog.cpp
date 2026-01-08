#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	:Animal("Dog"),
	m_brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other), m_brain(new Brain(*other.m_brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete m_brain;
}

Brain* Dog::getBrain()
{
	return m_brain;
}

const Brain* Dog::getBrain() const
{
	return m_brain;
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}

