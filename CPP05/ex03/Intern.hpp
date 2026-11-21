#pragma once 
#include "AForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern& operator=(const Intern &target);
        AForm* makeForm(const std::string &formName, const std::string &formTarget);
};