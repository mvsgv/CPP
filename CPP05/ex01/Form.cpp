#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Default constructor called." << std::endl;
}

Form::Form(std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
        if (gradeToExecute < 1 || gradeToSign < 1)
            throw GradeTooHightException();
        if (gradeToExecute > 150 || gradeToSign > 150)
            throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed),
     _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
        std::cout << "Copy constructor called." << std::endl;
}

Form::~Form(){
    std::string <<""<<std::endl;
}