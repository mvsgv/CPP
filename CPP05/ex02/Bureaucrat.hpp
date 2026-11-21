#pragma once

#include <string>
#include "AForm.hpp"
#include <iostream>
#include <exception>
class AForm;

class Bureaucrat{
    private :
        const std::string _name;
        int  _grade;
    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &target);
        
        class GradeTooHighException : public std::exception{
            const char* what() const throw(){
                return "Grade too high";
            }
        };
//Les classes d exception
//throw = ne lance pas d exception
//what = retourne le msg d erreur
        class GradeTooLowException : public std::exception {
            const char* what() const throw(){
                return "Grade too low";
            }
        };
        
        const std::string&  getName()const;
        int      getGrade(void) const;
        void    incrementGrade();
        void    decrementGrade();
        void    signAForm(AForm &AForm);

        void executeAForm(AForm const & AForm);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);