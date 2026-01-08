#ifndef AMATERIA_CPP
#define AMATERIA_CPP

#include <string>
// #include "ICharacter.hpp"

class	AMateria
{
	protected:
	std::string m_type;

	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria & other);
	virtual ~AMateria();

	const std::string& getType() const;
	virtual AMateria* clone() const =0;
	// virtual void use(ICharacter& target);
};

#endif