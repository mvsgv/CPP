#pragma once

#include "Bureaucrat.hpp"

class Form{
    private :
        const std::string _name;
        bool            _signed;
        const int       _gradeToSign;
        const int       _gradeToExecute;
    public :
        Form();
        Form(std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        ~Form();

        Form &operator=(const Form &target);
        
        class GradeTooHightException : public std::exception{
            const char* what() const throw(){
                return "Grade too high";
            }
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw(){
                return "Grade too low";
            }
        };

        const std::string& getName()const;
        bool    isSigned();
        int     getGradeToSign();
        int     getGradeToExecute();

        void    Signature(const Bureaucrat& bureaucrat);

    };

    std::ostream&   operator<<(std::ostream& os, const Form& form);