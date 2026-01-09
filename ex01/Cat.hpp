/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:59:39 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 22:59:40 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
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