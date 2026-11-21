#include "ScalarConverter.hpp"
#include <iostream>
#include <string>


int main(int argc, char **argv) {
    if (argc != 2){
        std::cout << "Usage: " << (argv[0] ? argv[0] : "ScalarConverter") << " literal" << std::endl;
            return 1;
    }
    std::string input = argv[1];
    ScalarConverter::convert(input);
    return 0;
}