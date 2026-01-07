#include "Animal.hpp"
#include <iostream>

Animal::Animal()
: m_type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
	: m_type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
	: m_type(other.m_type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makeSound() called" << std::endl;
}

std::string Animal::getType() const
{
	std::cout << "Animal getType() called" << std::endl;
	return m_type;
}