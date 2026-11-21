/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:49:57 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 16:49:58 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap{
    private:
        std::string _name;  //name
        unsigned int _HitPoints;     //health points
        unsigned int _EnergyPoints;  //energy to attack and repair
        unsigned int _AttackDamage;  //attack damage
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        
        ~ClapTrap();
        
        ClapTrap &operator=(const ClapTrap &target);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};