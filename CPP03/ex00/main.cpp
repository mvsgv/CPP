/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:50:04 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 19:55:35 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
		ClapTrap a;
		ClapTrap b("riri");

		a.attack("robot");
		a.takeDamage(10);
		a.takeDamage(55);
		a.beRepaired(5);
		a.attack("robot");
		b.beRepaired(0);
		for (int i = 0; i < 12; i++)
			b.attack("kiki");
		b.beRepaired(0);

}