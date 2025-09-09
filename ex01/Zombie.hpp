#pragma once

#include <iostream>
#include <string>

class Zombie{
    private:
        std::string name;
    public:
        Zombie();//constructeur
        ~Zombie();//destructeur
        void    setName(std::string name);//methode pour definir le nom
        void    announce(void);//methode pour annoncer les nom
};
Zombie*         zombieHorde( int N, std::string name );