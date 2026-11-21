/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:49:38 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 19:24:35 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing Construction Chain ===" << std::endl;
    FragTrap f("Fraggy");
    
    std::cout << "\n=== Testing FragTrap Methods ===" << std::endl;
    f.attack("enemy");
    f.highFivesGuys();
    f.takeDamage(50);
    f.beRepaired(25);
    
    std::cout << "\n=== Testing Energy Drain ===" << std::endl;
    // FragTrap has 100 energy points, so drain them all
    for (int i = 0; i < 100; i++) {
        f.attack("dummy");
    }
    
    std::cout << "\n=== No Energy Left ===" << std::endl;
    f.beRepaired(10);
    
    std::cout << "\n=== Testing All Classes ===" << std::endl;
    ClapTrap c("Clappy");
    ScavTrap s("Scavy");
    FragTrap f2("Fragster");
    
    c.attack("target");
    s.guardGate();
    f2.highFivesGuys();
    
    std::cout << "\n=== Destruction Chain (reverse order) ===" << std::endl;
    return 0;
}