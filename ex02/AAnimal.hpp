#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string m_type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		
		//Getters
		std::string getType() const;
};

#endif