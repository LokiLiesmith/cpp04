/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:59:41 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 22:59:41 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat"),
	m_brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other),
	m_brain(new Brain(*other.m_brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
}

Brain* Cat::getBrain()
{
	return m_brain;
}

const Brain* Cat::getBrain() const
{
	return m_brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}