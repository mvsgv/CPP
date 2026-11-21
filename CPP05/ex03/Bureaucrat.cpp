#include "Bureaucrat.hpp"

//commne name est un const on doit le declarer a l'initialisation et non construction 
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
    std::cout << "Default constructor for Bureaucrat " << this->getName() << " called with " <<
    this->getGrade() << " grade." << std::endl;
}

//throw - mecanisme pour gerer les erreurs de maniere propre quand qq chose d anormal se produit
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw GradeTooHighException();
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
        throw GradeTooHighException();
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

void Bureaucrat::signAForm(AForm &AForm){
    try{
        AForm.beSigned(*this);
        std::cout << this->_name<< " signed "<< AForm.getName() << std::endl;
    }
    catch (const std::exception& e){
        std::cout << this->_name << " couldn't sign " << AForm.getName() << " beacause "
        << e.what() << std::endl;
        }
}

void    Bureaucrat::executeAForm(AForm const & AForm){
    try{
        AForm.execute(*this);
        std::cout << this->getName() << " executed " << AForm.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't execute " << AForm.getName() <<
        " because " << e.what() << std::endl;
    }
}
/* 
Quand une erreur se produit (par exemple, une exception est lancée),
le bloc catch (const std::exception &e) attrape cette erreur.
e.what() est une methode de la classe std::exception qui retourne 
une chaine de caract décrivant l'erreur (msg explicite sur la cause de l exception)
std::exception &e : l’objet qui contient l’erreur.
e.what() : le message d’erreur associé à cette exception.
*/


