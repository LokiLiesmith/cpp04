#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
:	m_type("AMateria")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
: m_type(type)
{
	std::cout << "AMateria string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
	:m_type(other.m_type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other)
		m_type = other.m_type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

const std::string & AMateria::getType() const
{
	return m_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use called" << std::endl;
	(void)target;
}
//use will be added later
//Clone is a pure virtual so defined in derived classes