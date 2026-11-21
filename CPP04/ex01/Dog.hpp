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

        virtual void	makeSound() const;
		std::string 	getIdea(int idea_nr) const;
		void 			setIdea(int idea_nr, std::string idea);
};