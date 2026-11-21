#include "PhoneBook.hpp"
#include <string>

int main()
{
    Contact contact1;
    PhoneBook Book;
    std::string input;
    while(1)
    {
        Book.Welcome();
        std::cout << "Enter command (ADD, SEARCH, EXIT) :"<< std::endl;
        if (!(std::getline (std::cin, input)))
        {
            std::cerr << "Input error : Exit..." << std::endl;
            break;
        }
        if (input == "EXIT")
            break;
        if (input == "ADD"){
            Book.add();
        }
        if (input == "SEARCH"){
            Book.Search();
        }
        else{
            std::cout << "Unknown command. Please enter ADD, SEARCH or EXIT" <<std::endl;
        }
    }
    return 0;
}