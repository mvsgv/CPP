#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
    : AForm(copy), _target(copy._target) {
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &target) {
    if (this != &target) {
        AForm::operator=(target);
        this->_target = target._target;
    }
    std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (!getSigned())
        throw GradIsNotSignedException();
    if (executor.getGrade() < getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "***drilling noises*** "<< std::endl;
    std::srand(std::time(NULL));
	int nb = std::rand() % 2; // rand -> pour obtenir un nb aleatoire
	if (nb == 0)
        std::cout << this->_target << " has been robotomized." << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}
