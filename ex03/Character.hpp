#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria;

class Character: public ICharacter
{
	private:
		std::string		m_name;
		AMateria*		m_inventory[4];
		AMateria*		m_dropped[100];
		int				m_floorCount;
	
	public:
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif