#pragma once 

#include "Polymorphism.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *_brain;//?? why *
    public:
        Cat();
        Cat(const Cat& copy);
        Cat(std::string type);
        Cat &operator=(const Cat &target);
        virtual ~Cat();

    void 	makeSound() const;

};