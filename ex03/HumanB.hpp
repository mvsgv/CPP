#pragma once

#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *weaponType;
    public:
        void attack();
        
};
