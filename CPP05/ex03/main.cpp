#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
std::cout << "----\n"; // ShrubberyCreationAForm	
	try {
        Bureaucrat bob("Bob", 100);
        ShrubberyCreationForm shrubbery("home");

        std::cout << shrubbery << std::endl;

        // Bob signs the AForm
        bob.signAForm(shrubbery);

        // Bob tries to execute the AForm
        bob.executeAForm(shrubbery);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
std::cout << "----\n"; // RobotomyRequestAForm
    try {
        Bureaucrat bob("Bob", 72);
        RobotomyRequestForm robotomy("Bob");

        std::cout << robotomy << std::endl;

        // Bob signs the AForm
        bob.signAForm(robotomy);

        // Bob tries to execute the AForm
        bob.executeAForm(robotomy);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
std::cout << "----\n"; // PresidentialPardonAForm
    try {
        Bureaucrat bob("Bob", 5);
        PresidentialPardonForm pardon("Bob");

        std::cout << pardon << std::endl;

        // Bob signs the AForm
        bob.signAForm(pardon);

        // Bob tries to execute the AForm
        bob.executeAForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

std::cout << "----\n";   
    Intern someRandomIntern;
    AForm* form;
//test pour voir si mon intern peut creer des formulair
    form = someRandomIntern.makeForm("shrubbery creation", "Jardin");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("presidential pardon", "Fry");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (form)
        delete form;

    return 0;
}