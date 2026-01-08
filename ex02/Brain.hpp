#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string ideas[100];
		int m_count;

	public:
		Brain();
		void addIdea(const std::string& idea);
		std::string getIdea(int index) const;
};

#endif