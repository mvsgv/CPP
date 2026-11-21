#pragma once
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *weapon;
    public:
        void attack();
        HumanB(std::string name);
        void setWeapon(Weapon& w);
        
};

/*La vrai difference entre HumanA et HumanB est que HumanA possede une reference vers type d arme
a l encontre , HumanB possede un pointeur ver Weapon ce qui le rend sans arme a sa creation. HumanA possede
une arme a sa creation et ne peut etre construit/appele si sans elle et elle ne peut etre changee, tandis que HumanB 
peut etre cree sans arme , le pointeur peut etre change*/
