/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:00:15 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 23:00:15 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: AAnimal("Dog"),
	m_brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	: AAnimal(other), m_brain(new Brain(*other.m_brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
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

