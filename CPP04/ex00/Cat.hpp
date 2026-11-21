#pragma once 

#include "Polymorphism.hpp"

class Cat : public Animal{
    public:
        Cat();
        Cat(const Cat& copy);
        Cat(std::string type);
        Cat &operator=(const Cat &target);
        virtual ~Cat();

    void 	makeSound() const;
};