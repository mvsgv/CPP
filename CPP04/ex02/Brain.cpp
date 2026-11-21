#include "Brain.hpp"


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