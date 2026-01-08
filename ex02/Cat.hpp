#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *m_brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);		
		~Cat();

		Brain* getBrain();
		const Brain* getBrain() const;
		void makeSound() const;
};

#endif