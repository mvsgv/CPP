/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:49:38 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 18:45:18 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// int main()
// {
// 		ClapTrap a("bibi");
// 		ScavTrap k("merlino");

// 		a.attack("merlino");
// 		a.takeDamage(100);
// 		k.attack("bibi");
// 		k.takeDamage(150);
// 		a.beRepaired(0);
// 		k.GuardGate();
// 		a.attack("merlino");
// 		for (int i = 0; i < 50; i++)
// 			k.attack("bibi");
// 		k.beRepaired(0);

// }

int main()
{
    std::cout << "=== Testing ScavTrap ===" << std::endl;
    ScavTrap s("Bibiche");
    
    // Test GuardGate
    s.GuardGate();
    
    // Test attack with different stats
    s.attack("enemy Merlino");
    
    // Drain energy to see ASCII art
    std::cout << "\n=== Draining energy ===" << std::endl;
    for (int i = 0; i < 50; i++) {
        s.attack("Merlino");
    }
    
    std::cout << "\n=== Trying to repair with no energy ===" << std::endl;
    s.beRepaired(10);  // This will show the ASCII art!
    
    return 0;
}