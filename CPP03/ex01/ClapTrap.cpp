/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:49:28 by mavissar          #+#    #+#             */
/*   Updated: 2025/10/25 19:43:12 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
    std::cout << "ClapTrap constructor called"<< std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
    std::cout << "ClapTrap constructor for name "<< _name << " called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& copy){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    _name = copy._name;
    _HitPoints = copy._HitPoints;
    _EnergyPoints = copy._EnergyPoints;
    _AttackDamage = copy._AttackDamage;
}


ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &target){
    if (this != &target) 
    {
        this->_name = target._name;
        this->_HitPoints = target._HitPoints;
        this->_EnergyPoints = target._EnergyPoints;
        this->_AttackDamage = target._AttackDamage;
    }
    std::cout << "ClapTrap assignment operator called" << std::endl;
    return *this;
}


void    ClapTrap::attack(const std::string& target){
    if (this->_HitPoints == 0)
        std::cout << this->_name << " is already dead :(" << std::endl;
    else if (this->_EnergyPoints > 0)
    {
        this->_EnergyPoints -= 1;
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "Can't attack. Missing points." << std::endl;
    }
} 

void    ClapTrap::takeDamage(unsigned int amount){
    if (this->_HitPoints > amount)
        this->_HitPoints -= amount;
    else if (this->_HitPoints > 0)
        this->_HitPoints = 0;
    else
    {
       std::cout << "Can't kill me. I am already dead!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (this->_HitPoints == 0)
        std::cout << this->_name << " is already dead and can't be repaired :(" << std::endl;
    else if (this->_EnergyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " heals with " << amount << " hit points " << std::endl;
        this->_HitPoints += amount;
        this->_EnergyPoints -= 1;
    }
    else{
        std::cout << "Snif! No energy points left to resuscitate ✖𐃷✖" << std::endl;
        std::cout << "            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣤⣄⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  "<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡴⣶⠿⡛⢻⣍⠛⠭⠩⡍⠹⢩⢛⡛⠿⡟⢻⠶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⠾⢋⢉⠐⠠⠁⠈⠀⠄⠀⡀⠂⠀⠒⠀⠈⠀⢀⠀⠑⠢⠂⣉⢻⢷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⢀⣤⣞⠟⠁⠂⠁⠀⠈⠐⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠂⠀⠐⠀⠂⡀⢉⠽⢷⣤⡀⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "   ⠀⠀⠀⠀⢀⣴⡟⠯⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠛⠯⢿⣦⡀⠀⠀⠀⠀ "<< std::endl;
        std::cout << "    ⠀⠀⠀⣴⡿⢫⠜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⠳⣜⣿⣦⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⢠⣾⢋⡼⢁⢆⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢂⡡⡜⠧⣽⣷⡄⠀"<< std::endl;
        std::cout << "    ⢠⣿⡗⢊⠴⣩⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠐⡘⡐⠠⣿⣿⡄"<< std::endl;
        std::cout << "    ⣾⣿⠾⡁⢊⠔⡸⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠄⠀⠁⠉⡒⣿⣿⡇"<< std::endl;
        std::cout << "    ⣿⣿⡟⢣⠘⠀⠠⠀⠘⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⡀⣄⡠⠀⠀⣇⢿⣿⣿"<< std::endl;
        std::cout << "    ⣿⣿⡍⢧⡘⠀⠉⡅⠀⠘⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⢠⠖⠁⢴⡾⠟⠀⠀⢀⣿⣾⣿⣿"<< std::endl;
        std::cout << "    ⣿⣿⣞⢵⢇⡄⠀⠙⠦⠤⢣⠌⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣴⠾⠔⠋⠂⠠⠔⠉⠀⠀⠀⠀⡾⣻⣿⣻⣿"<< std::endl;
        std::cout << "    ⣿⣿⡽⣿⣸⡁⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⡀⠀⠀⠒⢀⡀⠀⢐⠞⠀⠀⢀⠄⠐⠀⠁⡐⠀⠀⠀⠀⠀⠀⣼⣓⣿⣟⣿⣇"<< std::endl;
        std::cout << "    ⣿⣿⣞⣽⣷⡇⠀⣶⣴⣶⣶⣤⣤⣤⣉⣀⣀⡀⡴⣄⠀⠀⠀⠠⠊⠁⠀⠀⣁⣄⣀⣀⣤⣴⣦⣶⣶⣶⣤⣄⠐⢿⣿⣟⣴⣺⠀"<< std::endl;
        std::cout << "    ⣿⣿⠾⣽⣿⠗⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣝⡞⡗⢀⠜⠁⠀⠀⢸⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠐⣿⢿⣘⡇⠀"<< std::endl;
        std::cout << "    ⣿⣿⢿⣿⣟⢸⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣼⣏⣴⠀⣆⡰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⢻⣟⡕⠁⠀"<< std::endl;
        std::cout << "    ⣿⣿⣿⢾⡇⢸⣿⣯⠹⣶⣻⣽⣿⣿⣿⣿⣿⣿⣿⠿⣼⢯⣿⣼⣟⣰⢿⣼⣿⣿⣿⣿⣿⣿⢿⣻⣯⢷⣻⣿⢿⡇⢸⣿⣿⠁⠀"<< std::endl;
        std::cout << "    ⣿⣿⣿⣻⡇⠸⣿⣿⣿⣶⣿⣷⣿⣿⣿⣿⣿⣿⠛⣼⣟⣶⣿⣿⣟⣾⣹⣧⡹⣿⣿⣿⣿⣿⣿⣷⣯⣷⣯⣿⣻⠇⠸⢺⣿⠀⠀"<< std::endl;
        std::cout << "    ⢿⣿⣿⣿⡃⠂⠻⣿⣿⣿⣿⣿⣿⡿⠿⠟⠋⢀⣼⣿⡾⢰⣿⣿⣿⣎⢿⣿⣯⠉⠙⠻⠿⣿⣿⣿⣿⣷⣿⡿⠌⠀⠘⢝⣿⡇⠀"<< std::endl;
        std::cout << "    ⣿⣿⣹⠷⣻⣶⣤⡠⢈⠉⠉⣩⣤⣤⣴⣶⡿⢋⣶⣿⣧⣿⣿⣿⣿⣿⣜⢧⡀⠃⠚⠶⣦⣤⣄⡉⠉⠉⠁⠀⠀⠀⠾⠂⣿⡇⡀"<< std::endl;
        std::cout << "    ⠉⢿⣽⡀⠀⠀⠀⠉⠈⠛⠉⣩⣟⣩⠞⠉⠠⣾⣿⢡⣿⣿⢿⣿⣿⣿⣿⣌⣧⠀⠀⠀⠉⠙⠻⣤⡑⠀⠃⠀⠀⠀⠀⡩⣽⣿⠏"<< std::endl;
        std::cout << "    ⠀⠀⠙⢷⣤⣈⠀⠀⣀⣀⣺⡿⠋⠀⠀⠀⣸⠃⠃⡟⢿⣿⣿⣿⣿⣿⡿⢿⢸⡄⠀⠀⠀⠀⠀⠘⠦⣄⡀⢀⠀⡀⣰⡯⢿⠏⠁"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⢹⣻⣿⣻⣿⣿⣯⣇⠀⢨⠆⢰⡇⠀⡆⢳⣘⣿⣿⣿⣿⣿⣿⠃⠈⢣⠀⢠⠀⠨⡀⢤⣾⣿⣿⣿⣿⣿⡿⠊⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠸⠿⣿⣿⡈⠉⠉⣿⣖⡟⠀⣿⠀⢠⡇⠀⠈⠉⠉⠛⠉⠉⠀⠀⠀⠘⡇⠘⡇⣰⣿⡿⠉⠉⢈⣿⣿⡿⠃⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⣿⣿⡗⢰⡟⠀⢻⠃⢀⠄⠀⠀⢠⠃⠀⠀⠄⠀⠀⠁⣶⡇⢾⣿⣧⠀⠀⣸⢻⣯⣗⠃⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⣿⡏⣿⡀⢠⣿⣽⡇⢸⠃⢀⡿⠀⢸⡆⠀⠀⢽⡀⠀⠀⣠⠀⢧⡂⢸⣷⢸⣿⡿⡄⢠⣿⣸⣯⡃⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⢀⣿⣧⢻⣧⣸⡇⢸⠉⢻⡓⠾⡧⢤⣸⣇⣀⣀⠘⣀⣀⣰⣿⡤⣿⠷⢻⡟⠛⡅⢻⣁⣾⡟⣿⣿⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⢸⣿⣿⡜⣿⣿⣿⣷⡄⣼⠀⢸⡇⠀⣿⠃⠀⠘⣿⠁⠀⢸⡇⠀⢸⡄⠀⡇⢠⣿⣿⣿⣿⢣⣿⣿⡆⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⢸⣿⣿⡇⢿⣿⡏⢹⠿⢧⣤⡼⣄⣀⣾⠀⠀⠀⣿⠀⠀⢸⣇⣀⣨⣧⣤⡿⡟⡏⣹⣿⣿⣼⣿⣿⡇⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⢸⣿⣿⣿⡞⣿⣿⣿⣄⢀⣧⠉⣷⠉⢳⡟⠓⠚⡿⠓⠚⢻⡎⠉⡟⠁⣟⢀⣠⣷⣿⠋⣍⣾⣿⣟⡇⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠈⣿⣿⣿⣷⠸⣿⣿⡍⢻⡷⠿⠿⢤⢼⣧⣀⣠⣿⣄⣀⣾⣄⡤⣿⠶⣿⡯⣽⣿⡯⢑⣾⣿⣿⣿⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠘⢿⣿⢿⡧⢹⣿⢏⢸⠃⠀⢆⠀⠀⠀⠀⠀⠀⠀⠀⠘⠋⠐⠻⠀⢸⣇⣹⡿⢧⣹⣿⣯⡿⠃⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "   ⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⠇⡌⢻⢮⣁⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡿⡏⢰⣾⣷⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀ "<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣦⡣⣌⠐⠈⠂⠀⠁⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⢙⣹⢃⠱⢨⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢦⡦⡆⢀⡖⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⢻⣇⣾⡼⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠯⣤⣀⠀⠀⠀⠀⠘⠇⠀⠀⢀⣀⣤⠿⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
        std::cout << "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠈⠉⠉⠒⠒⠛⠓⠚⠉⠉⠁⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;

    }
}
