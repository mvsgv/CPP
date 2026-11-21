#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
    : AForm(copy), _target(copy._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &target){
        AForm::operator=(target);
        this->_target = target._target;
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (!getSigned())
        throw GradIsNotSignedException();
    if (executor.getGrade() < getGradeToExecute())
        throw GradeTooLowException();
    else   
        std::cout << this->_target << " had been pardoned by Zaphod Beenlebtox." << std::endl;
 }