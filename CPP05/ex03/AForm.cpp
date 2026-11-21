#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
        if (gradeToExecute < 1 || gradeToSign < 1)
            throw GradeTooHighException();
        if (gradeToExecute > 150 || gradeToSign > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed),
     _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
        std::cout << "AForm copy constructor called." << std::endl;
}

AForm::~AForm(){
    std::cout << "AForm destructor called."<<std::endl;
}

AForm &AForm::operator=(const AForm &target){
    if (this != &target)
        this->_signed = target._signed;
    return *this;
}

bool    AForm::getSigned()const {
    return _signed;
}

const std::string& AForm::getName()const{
    return (this->_name);
}

int    AForm::getGradeToSign() const{
    return _gradeToSign;
}

int     AForm::getGradeToExecute() const{
    return _gradeToExecute;
}

bool    AForm::beSigned(Bureaucrat &Bureaucrat){
    if (Bureaucrat.getGrade() <= _gradeToSign){
        _signed = true;
        return true;
    }
    else {
        throw GradeTooLowException();
    }
}
        
void    AForm::Signature(const Bureaucrat& bureaucrat){
    if (this->_signed){
        throw GradIsNotSignedException();
    }
    if (bureaucrat.getGrade() > this->_gradeToExecute){
        throw AForm::GradeTooLowException();
    }
    std::cout << bureaucrat.getName() << " executed " << this->_name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm &AForm) {
    os << AForm.getName() << ", AForm grade " << AForm.getGradeToSign() 
       << ", execution grade " << AForm.getGradeToExecute() 
       << ". Signed: " << (AForm.getSigned() ? "Yes" : "No");
    return os;
}

void    AForm::execute(const Bureaucrat& exec) const {
    if (!getSigned())
        throw GradIsNotSignedException();
    if (exec.getGrade() < getGradeToExecute())
        throw GradeTooLowException();
    else{
        std::cout << "Executor " << exec.getName() << " signed AForm: " << this->_name << std::endl;
    }
}
