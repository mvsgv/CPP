#pragma once 
#include <stack>
#include <string>
#include <exception>
#include <iostream>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <sstream>

class RPN{
    public:
        RPN();
        ~RPN();
        int executeRPN(const std::string &expression);
    private:
        std::stack<int> _stack;
        void    calcul(char op);
};