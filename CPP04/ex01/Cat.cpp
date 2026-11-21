#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
    _brain = new Brain();
    std::cout << "Default constructor for Cat called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type){
    _brain = new Brain();
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy){
    _brain = new Brain(*(copy._brain)); //deep copy 
    std::cout << "Copy constructor for Cat called." << std::endl;
}

Cat	&Cat::operator=(const Cat &target){
	std::cout << "Copy assignment operator for Cat called." << std::endl;
    this->_type = target._type;
    delete _brain;//je supprime car je remplace old brain par new brain -> sinon j ai des memory leaks
    _brain = new Brain(*(target._brain));
    return *this;
}

Cat::~Cat(){
    delete _brain;
    std::cout << "Destructor for Cat called." << std::endl;
}

void 	Cat::makeSound() const{
	std::cout << "Meow bitch." << std::endl;
}

std::string Cat::getBrain(int idea_nb) const{
        if (idea_nb >= 0 && idea_nb < 100)
            return (_brain->getIdea(idea_nb));
        else    
            return ("Cat brain has no ideas.");
}

void    Cat::setBrain(int idea_nb, std::string new_idea)
{
	if (idea_nb >= 0 && idea_nb < 100)
		_brain->setIdea(idea_nb, new_idea);
	else
		std::cout << "Cat brain can just save 100 ideas";
}