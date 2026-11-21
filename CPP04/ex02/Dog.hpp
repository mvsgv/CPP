#pragma once 

#include "Polymorphism.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog& copy);
        Dog(std::string type);
        Dog &operator=(const Dog &target);
        virtual ~Dog();

        void    makeSound() const;
};