#pragma once

#include <string>
#include <iostream>

class ClapTrap{
    private:
        std::string _name;
        int _HitPoints;
        int _EnergyPoints;
        int _AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        
        ~ClapTrap();
        
        ClapTrap &operator=(const ClapTrap &target);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
}