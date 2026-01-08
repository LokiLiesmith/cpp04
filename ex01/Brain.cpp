#include "Brain.hpp"

Brain::Brain()
: m_count(0)
{
}

void Brain::addIdea(const std::string& idea)
{
	if (m_count < 100)
	{
		ideas[m_count] = idea;
		m_count++;
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < m_count)
		return ideas[index];
	return "";
}
