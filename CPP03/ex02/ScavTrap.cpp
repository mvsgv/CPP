/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:49:45 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 19:30:12 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Inheritance is a fundamental concept in OOP (Object Oriented Programming). 
It is the mechanism by which one class is allowed to inherit the features of another class. 
Inheritance means creating new classes based on existing ones. 
A class that inherits from another class can reuse the methods and fields of that class.

Example: Animal is the base class and Dog,
Cat and Cow are derived classes that extend the Animal class.*/

/*Access Specifiers in C++

private
1) Only accessible within the same class
2) Child classes cannot access private members of parent class
3) Completely hidden from outside world

protected
1) Accessible within the same class AND its derived classes
2) Still hidden from outside world (like private)
3) Perfect for inheritance scenarios

public
1) Accessible from anywhere
2) No restrictions
*/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy){
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap name constructor called for "<< this->_name << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &target){
    if (this != &target){
        ClapTrap::operator=(target);
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

void    ScavTrap::attack(const std::string &target){
    if (this->_HitPoints == 0)
        std::cout << "ScavTrap: " << this->_name << " is already dead :(" << std::endl;
    else if (this->_EnergyPoints > 0)
    {
        this->_EnergyPoints -= 1;
        std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "ScavTrap can't attack they're missing points." << std::endl;
    }
} 

void    ScavTrap::guardGate(void){
    if (this->_HitPoints > 0)
        std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
    return;
}