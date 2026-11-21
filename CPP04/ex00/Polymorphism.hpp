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
        virtual void makeSound() const;
        std::string getType() const;
};

//polymorpfism dynamique ?