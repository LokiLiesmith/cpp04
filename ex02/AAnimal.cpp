/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:00:21 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 23:00:21 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
: m_type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
	: m_type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
	: m_type(other.m_type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
		m_type = other.m_type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

//its now a pure virtual function, needs to be defined by derived classes
// void AAnimal::makeSound() const
// {
// 	std::cout << "AAnimal makeSound() called" << std::endl;
// }

std::string AAnimal::getType() const
{
	std::cout << "AAnimal getType() called" << std::endl;
	return m_type;
}