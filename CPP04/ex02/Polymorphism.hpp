#pragma once

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal& copy);
        Animal(std::string type);
        Animal &operator=(const Animal &target);
        virtual ~Animal();
        virtual void makeSound() const = 0; // Une classe abstraite est une classe avec au moins une pure virtuelle
        std::string getType() const;
};

// La classe animal devient abstaite de cette maniere je ne pourrai pas utiliser animal comme objet
/*on va reussir a creer des classes enfant avec mais pas en l utilisant elle meme, car Animal n est pas complet
cette facon force l heritage */