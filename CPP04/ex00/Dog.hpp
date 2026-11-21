#pragma once 

#include "Polymorphism.hpp"

class Dog : public Animal{
    public:
        Dog();
        Dog(const Dog& copy);
        Dog(std::string type);
        Dog &operator=(const Dog &target);
        virtual ~Dog();

        void    makeSound() const;
};