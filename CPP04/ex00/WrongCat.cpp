#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    this->_type = "WrongCat";
    std::cout << "WrongCat default constructor called."<< std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type){
	_type = type;
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy){
    *this = copy;
    std::cout << "Copy constructor for WrongCat called." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &target){
    this->_type = target._type;
	std::cout << "Copy assignment operator for WrongCat called." << std::endl;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "Destructor for WrongCat called." << std::endl;
}

void 	WrongCat::makeSound() const{
	std::cout << "Meow warf bitch." << std::endl;
}
