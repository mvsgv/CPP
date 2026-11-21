#include "Brain.hpp"

//Encapsulation ->
/*is the technique of hiding the data and functions that operate on class members. 
Think of it like a protective shell that surrounds an object to protect its 
internal state from tampering or unwanted access. 
In other words, it protects the data from unauthorized access and modification.*/

Brain::Brain(){
    std::cout << "Brain default constructor called." << std::endl;
    for (int i = 0; i < 100; i++){
        ideas[i] = "Default idea";
    }
}

Brain::Brain(const Brain &copy){
    *this = copy;
    std::cout << "Brain copy construcor called." << std::endl;
}

Brain &Brain::operator=(const Brain &target){
    for (int i = 0; i < 100; i++){
        ideas[i] = target.ideas[i];
    }
	std::cout << "Assignment operator for Brain called." << std::endl;
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destructor called."<< std::endl;
}   

std::string Brain::getIdea(int index) const{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "No idea ..";
}

void    Brain::setIdea(int i, std::string &idea){
    if (i >= 0 && i < 100) 
        ideas[i] = idea;
}
