#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->type = type;
}

/*
const std::string 
const est le type de retour -> signifie qu on ne peut changer sa valeur
std::string& signifie qu on retourne une reference et non une copie 
pas de copie = plus rapide et plus economique niveau memoire

Weapon::getType() 
signigfie que cette methode appartient a la classe Weapon
getType - nom de la methode -> getter 

const (a la fin) - signifie que l objet n est pas modifie.
ne change aucun attribut

en bref cette methode permet de lire le type d are de maniere securisee 
et efficace sans copier le resultat ni modifier l objet
*/
const std::string& Weapon::getType() const{
    return this->type;
}

void Weapon::setType(std::string NewType){
    this->type = NewType;
}