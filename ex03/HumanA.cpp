#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weaponType(weapon){
}

void    HumanA::attack(){
    std::cout << name <<" attacks with their " << weaponType.getType() << std::endl;
}