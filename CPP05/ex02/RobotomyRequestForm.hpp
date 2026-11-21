#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &target);

        void    execute(Bureaucrat const &executor) const;
};