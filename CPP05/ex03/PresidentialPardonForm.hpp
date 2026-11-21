#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string  _target;
    public:
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &target);

        void    execute(Bureaucrat const &executor) const;
};