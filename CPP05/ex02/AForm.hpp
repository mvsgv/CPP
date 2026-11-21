#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>


class Bureaucrat;

class AForm {
    private :
        const std::string _name;
        bool            _signed;
        const int       _gradeToSign;
        const int       _gradeToExecute;
    public :
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &target);
        ~AForm();

        class GradeTooHighException : public std::exception{
            const char* what() const throw(){
                return "Grade too high";
            }
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw(){
                return "Grade too low";
            }
        };
        class GradIsNotSignedException : public std::exception{
            const char* what() const throw(){
                return "Grade is not signed";
            }
        };

        const   std::string& getName()const;
        bool    getSigned() const ;
        int     getGradeToSign() const ;
        int     getGradeToExecute() const;
        bool    beSigned(Bureaucrat &Bureaucrat);
        void    Signature(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat & exec) const = 0;

    };

    std::ostream&   operator<<(std::ostream& os, const AForm& AForm);