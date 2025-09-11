#include "HumanB.hpp"

std::string HumanB::weaponType(std::string type){
    this->type = type;
}

void    HumanB::attack(){
    std::cout << "attacks with their " << weaponType << std::endl;
}