#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(std::string name)
	:	m_name(name), m_floorCount(0)
{
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	for(int i = 0; i < 100; i++)
		m_dropped[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character& other)
	:	m_name(other.m_name), m_floorCount(other.m_floorCount)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.m_inventory[i])
			m_inventory[i] = other.m_inventory[i]->clone();
		else
			m_inventory[i] = NULL;
	}

	for (int i = 0; i < 100; i++)
	{
		if (other.m_dropped[i])
			m_dropped[i] = other.m_dropped[i]->clone();
		else
			m_dropped[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		m_name = other.m_name;

		for(int i = 0; i < 4; i++)
		{
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}

		for (int i = 0; i < 4; i++)
		{
			if (other.m_inventory[i])
				m_inventory[i] = other.m_inventory[i]->clone();
			else
				m_inventory[i] = NULL;
		}
		//clear current dropped
		for (int i = 0; i < 100; i++)
		{
			delete m_dropped[i];
			m_dropped[i] = NULL;
		}
		//assign dropped from other
		for (int i = 0; i < 100; i++)
		{
			if (other.m_dropped[i])
				m_dropped[i] = other.m_dropped[i]->clone();
			else
				m_dropped[i] = NULL;
		}
		m_floorCount = other.m_floorCount;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_inventory[i];
		m_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		delete m_dropped[i];
		m_dropped[i] = NULL;
	}
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for(int i = 0; i < 4; i++)
	{
		if (m_inventory[i] == NULL)
		{
			m_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !m_inventory[idx])
        return;

    if (m_floorCount >= 100)
        return ; // can't drop (prevents losing pointer)

    m_dropped[m_floorCount++] = m_inventory[idx];
    m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx < 4 && idx >= 0 && m_inventory[idx])
		m_inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return m_name;
}
