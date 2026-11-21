#include "Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
    _brain = new Brain();
    std::cout << "Default constructor for Dog called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type){
	_type = type;
    _brain = new Brain();
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy){
    this->_type = copy._type;
    _brain = new Brain(*(copy._brain));
    std::cout << "Copy constructor for Dog called." << std::endl;
}

Dog	&Dog::operator=(const Dog &target){
    if (this != &target) {
        Animal::operator=(target);
        *_brain = *target._brain;
    }
	std::cout << "Copy assignment operator for Dog called." << std::endl;
    return *this;
}

Dog::~Dog(){
    delete _brain;
    std::cout << "Destructor for Dog called." << std::endl;
}

void 	Dog::makeSound() const{
	std::cout << "Waff bitch." << std::endl;
}