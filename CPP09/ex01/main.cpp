#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    RPN rpn;
    try{
        int res = rpn.executeRPN(av[1]);
        std::cout << res << std::endl;
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}