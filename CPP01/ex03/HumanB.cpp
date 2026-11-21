#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL){}
/*
l attribut name recevra la valeur du parametre name ->c est pour connaitre le nom de HumanB
weapon(nullptr) un pointeur est initialise a nullptr donc HumanB n a pas d armeau debut ->on saut que c est un pointeur car je le declare comme tel dans le .hpp
*/

void HumanB::setWeapon(Weapon& w){
    this->weapon = &w;
}

void    HumanB::attack(){
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout <<name << " has no weapon" << std::endl; 
}