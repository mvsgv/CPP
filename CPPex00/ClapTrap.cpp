#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {

    std::cout << "ClapTrap constructor called"<< std::endl;
}

ClapTrap::ClapTrap(std::string name): _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
    std::cout << "ClapTrap constructor for name "<< _name << "called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& copy){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    _name = copy._name;
    _HitPoints = copy._HitPoints;
    _EnergyPoints = copy._EnergyPoints;
    _AttackDamage = copy._EnergyPoints;
}


ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &target){
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->_name = target._name;
    this->_HitPoints = target._HitPoints;
    this->_EnergyPoints = target._EnergyPoints;
    this->_AttackDamage = target._AttackDamage;
    return *this;
}

void    ClapTrap::attack(const std::string& target){
    if (this->_HitPoints == 0)
        std::cout << this->_name << " is already dead :(" << std::endl;
    else if (this->_EnergyPoints > 0)
    {
        this->_EnergyPoints =- 1;
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "Can't attack. Missing points." << std::endl;
    }
} 

void    ClapTrap::takeDamage(unsigned int amount){
    if (this->_HitPoints == 0 || amount != 0)
        std::cout << this->_name << " is already dead :(" << std::endl;
    else{
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        if (amount > this->_HitPoints)
            this->_HitPoints = 0;
        else
            this->_HitPoints-= amount;
    }
}

void    beRepaired(unsigned int amount){

}
