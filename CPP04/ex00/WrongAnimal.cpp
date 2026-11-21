#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->_type = "Default";
    std::cout << "Default constructor for WrongAnimal called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
    std::cout << "Constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &target){
    this->_type = target._type;
    std::cout << "Copy constructor WrongAnimal called."<< std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destructor for WrongAnimal called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &target){
    this->_type = target._type;
	std::cout << "Copy assignment operator for Animal called." << std::endl;
    return *this;
}

void    WrongAnimal::makeSound() const{
    std::cout << "Wrong animals make wrong sounds." << std::endl;
}

std::string WrongAnimal::getType() const {
    return (_type);
}