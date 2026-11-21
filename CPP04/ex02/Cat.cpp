#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
    _brain = new Brain();
    std::cout << "Default constructor for Cat called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type){
	_type = type;
    _brain = new Brain();
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy){
    this->_type = copy._type;
    _brain = new Brain(*(copy._brain));
    std::cout << "Copy constructor for Cat called." << std::endl;
}

Cat	&Cat::operator=(const Cat &target){
    if (this != &target) {
        this->_type = target._type;
        delete _brain;
        _brain = new Brain(*(target._brain));
    }
	std::cout << "Copy assignment operator for Cat called." << std::endl;
    return *this;
}

Cat::~Cat(){
    delete _brain;
    std::cout << "Destructor for Cat called." << std::endl;
}

void 	Cat::makeSound() const{
	std::cout << "Meow bitch." << std::endl;
}
