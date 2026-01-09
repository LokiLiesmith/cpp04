/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:00:16 by mrazem            #+#    #+#             */
/*   Updated: 2026/01/09 23:00:16 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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