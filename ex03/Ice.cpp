#include "Ice.hpp"
#include <iostream>

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other)
	: AMateria(other) 
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}
