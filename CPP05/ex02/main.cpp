#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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


    return 0;
}

