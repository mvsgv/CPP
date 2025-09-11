#pragma once

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
    private:
        std::string name;
        Weapon& weaponType;//reference a une arme
    public:	
		void    attack();
		HumanA(std::string name, Weapon& weapon);
};