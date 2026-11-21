#pragma once 

#include "Polymorphism.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat& copy);
        Cat(std::string type);
        Cat &operator=(const Cat &target);
        virtual ~Cat();

    virtual void 	makeSound() const;
    std::string getBrain(int idea_nb) const;
    void    setBrain(int idea_nb, std::string new_idea);

};