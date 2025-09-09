#pragma once

#include <iostream>
#include <string>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(std::string type);//constructeur
        const std::string &getType() const;//retourne une reference constante
        void setType(std::string NewType);//definit un nouveau type
};