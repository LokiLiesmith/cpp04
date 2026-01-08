#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class	Ice: public AMateria
{
	private:

	public:
	Ice();
	Ice(const Ice& other);
	~Ice();

	AMateria* clone() const;

};

#endif