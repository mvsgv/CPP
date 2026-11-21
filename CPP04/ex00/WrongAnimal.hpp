#pragma once 

#include <string>
#include <iostream>

class WrongAnimal{
    protected:
        std::string _type;
    public: 
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &target);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &target);

        void    makeSound() const;
        std::string getType() const;
};