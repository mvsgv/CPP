#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
    std::cout << "Default constructor for Cat called." << std::endl;
}

Cat::Cat(std::string type){
	_type = type;
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy){
    this->_type = copy._type;
    std::cout << "Copy constructor for Cat called." << std::endl;
}

Cat	&Cat::operator=(const Cat &target){
    this->_type = target._type;
	std::cout << "Copy assignment operator for Cat called." << std::endl;
    return *this;
}

Cat::~Cat(){
    std::cout << "Destructor for Cat called." << std::endl;
}

void 	Cat::makeSound() const{
	std::cout << "Meow bitch." << std::endl;
}
