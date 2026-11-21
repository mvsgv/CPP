#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &copy){
   (void)copy;
}

Intern& Intern::operator=(const Intern &target){
    (void) target;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget){
    int i = 0;
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    while (i < 3 && formName != forms[i])
        i++;
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        return (new ShrubberyCreationForm(formTarget));
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        return (new RobotomyRequestForm(formTarget));
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        return (new PresidentialPardonForm(formTarget));
    default:
        std::cout << "Form does not exist" << std::endl;
        return NULL;
    }
}