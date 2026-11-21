/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:00:23 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 19:32:46 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;    
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy){
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap name constructor called" << std::endl;  
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &target){
    if (this != &target)
        ClapTrap::operator=(target);
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

void    FragTrap::highFivesGuys(void){
    if (this->_HitPoints > 0)
        std::cout << "FragTrap " << this->_name<< " asks to stop for devil's sake and give them a high five!" << std::endl;
    else
        std::cout << "FragTrap " << this->_name << " never received a high five and died of sadness" << std::endl;
}