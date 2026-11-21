#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationAForm destructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
    : AForm(copy), _target(copy._target) {
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &target) {
    if (this != &target) {
        AForm::operator=(target); // Appel de l'opérateur d'affectation de la classe de base
        this->_target = target._target;
    }
    std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned())
        throw ("Form not signed.");
    if (executor.getGrade() > getGradeToExecute())
        throw ("Grade too low to execute");
    std::string filename = _target + "_shrubbery";std::ofstream
    file(filename.c_str());
    if (!file)
        throw ("Cannot open file.");
    file << "      /\\\n";
    file << "     /\\*\\\n";
    file << "    /\\O\\*\\\n";
    file << "   /*/\\/\\/\\\n";
    file << "  /\\O\\/\\*\\/\\\n";
    file << " /\\*\\/\\*\\/\\/\\\n";
    file << "/\\O\\/\\/*/\\/O/\\\n";
    file << "      ||      \n";
    file << "      ||      \n";
    file.close();
}
