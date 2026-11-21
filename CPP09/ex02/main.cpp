#include "PmergeMe.hpp"


static bool checkArguments(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::string arg = av[i];
        
        if (arg.empty()) 
            return false;

        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) 
            return false;
        }
        char *endptr;
        long val = std::strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || val > INT_MAX)
            return false;
    }
    return true;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    if (!checkArguments(ac, av)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        PmergeMe program;
        program.run(ac, av);
    } 
    catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}