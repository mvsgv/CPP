#pragma once

#include <string>
#include <iostream>
#include <exception>

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
        
        class GradeTooHightException : public std::exception{
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

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);