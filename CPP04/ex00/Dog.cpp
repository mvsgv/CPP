#include "Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
    std::cout << "Default constructor for Dog called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type){
	_type = type;
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy){
    this->_type = copy._type;
    std::cout << "Copy constructor for Dog called." << std::endl;
}

Dog	&Dog::operator=(const Dog &target){
    this->_type = target._type;
	std::cout << "Copy assignment operator for Dog called." << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Destructor for Cat called." << std::endl;
}

void 	Dog::makeSound() const{
	std::cout << "Waff bitch." << std::endl;
}