#pragma once

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
        public: 
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &target);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &target);

        void    makeSound() const;
};


