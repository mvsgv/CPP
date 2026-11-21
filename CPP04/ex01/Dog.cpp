#include "Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
    _brain = new Brain();
    std::cout << "Default constructor for Dog called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type){
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

std::string Dog::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (_brain->getIdea(i));
	else
		return ("Dog brain cant have more than a 100 ideas");
}

void Dog::setIdea(int i, std::string new_idea)
{
	if (i >= 0 && i < 100)
		_brain->setIdea(i, new_idea);
	else
		std::cout << "Dog brain cant have more than a 100 ideas";
}