/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:00:44 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 23:00:44 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		m_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.m_templates[i])
			m_templates[i] = other.m_templates[i]->clone();
		else
			m_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete m_templates[i];
			m_templates[i] = NULL; 
		}

		for(int i = 0; i < 4; i++)
		{
			if (other.m_templates[i])
				m_templates[i] = other.m_templates[i]->clone();
			else
				m_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_templates[i])
		{
			delete m_templates[i];
			m_templates[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	if (m == NULL)
		return ;
	while (i < 4)
	{
		if(m_templates[i] == NULL)
		{
			m_templates[i] = m;
			return ;
		}
		i++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if (m_templates[i] && m_templates[i]->getType() == type)
			return m_templates[i]->clone();
	}
	return 0;
}