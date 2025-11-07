#include "Bureaucrat.hpp"

//commne name est un const on doit le declarer a l'initialisation et non construction 
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
    std::cout << "Default constructor for Bureaucrat " << this->getName() << " called with " <<
    this->getGrade() << " grade." << std::endl;
}

//throw - mecanisme pour gerer les erreurs de maniere propre quand qq chose d anormal se produit
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw GradeTooHightException();
    if (grade > 150)
        throw GradeTooLowException();
     std::cout << "Constructor for Bureaucrat " << this->getName() << " called with " <<
    this->getGrade() << " grade." << std::endl;
}

//utiliser la list d initialisation car const
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){
    std::cout << "Copy constructor for Bureaucrat "<< this->getName() << " called." << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor for Bureaucrat "<< this->getName() << " called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target){
    if (this != &target){
        this->_grade = target._grade;
    }
    return *this;
}

int  Bureaucrat::getGrade(void)const{
    return (this->_grade);
}

const std::string&    Bureaucrat::getName(void)const{
    return (this->_name);
}

void    Bureaucrat::incrementGrade(){
    if (_grade - 1 < 1)
        throw GradeTooHightException();
    _grade--;
}

void    Bureaucrat::decrementGrade(){
    if (_grade + 1 > 150)
        throw GradeTooLowException();    
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}