#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Test 1: Création valide ===" << std::endl;
    try {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade trop haut (0) ===" << std::endl;
    try {
        Bureaucrat b2("Bob", 0);
        std::cout << b2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade trop bas (151) ===" << std::endl;
    try {
        Bureaucrat b3("Charlie", 151);
        std::cout << b3 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment (3 → 2 → 1) ===" << std::endl;
    try {
        Bureaucrat b4("Diana", 3);
        std::cout << b4 << std::endl;
        
        b4.incrementGrade();  // 3 → 2
        std::cout << b4 << std::endl;
        
        b4.incrementGrade();  // 2 → 1
        std::cout << b4 << std::endl;
        
        b4.incrementGrade();  // 1 → 0 (ERREUR!)
        std::cout << b4 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement (148 → 149 → 150) ===" << std::endl;
    try {
        Bureaucrat b5("Eve", 148);
        std::cout << b5 << std::endl;
        
        b5.decrementGrade();  // 148 → 149
        std::cout << b5 << std::endl;
        
        b5.decrementGrade();  // 149 → 150
        std::cout << b5 << std::endl;
        
        b5.decrementGrade();  // 150 → 151 (ERREUR!)
        std::cout << b5 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}