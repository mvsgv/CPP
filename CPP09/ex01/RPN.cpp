#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

int    RPN::executeRPN(const std::string &expression){
    std::istringstream iss(expression);
    std::string token;

    while(iss >> token)
    {
        if (token.size() == 1 && strchr("+-*/", token[0])){
            if (_stack.size() < 2)
            throw std::runtime_error("Error: insufficient operands");
        calcul(token[0]);
        }
        else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))){
            _stack.push(static_cast<int>(token[0] - '0'));
        }
        else{
            throw std::runtime_error("Error: please use digit between 0 and 9 or operands '+-*/' ");
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    return _stack.top();
}

void    RPN::calcul(char op){
    int second = _stack.top(); _stack.pop();
    int first =_stack.top(); _stack.pop();
    long res;

    switch(op){
        case '+':
            res = static_cast<long> (first) + static_cast<long> (second);
            if (res > INT_MAX || res < INT_MIN)
                throw std::runtime_error("Error: result oveflow or underflow");
            break;
        case '-':
            res = static_cast<long> (first) - static_cast<long> (second);
            if (res > INT_MAX || res < INT_MIN)
                throw std::runtime_error("Error: result overflow or underflow");
            break;
        case '*':
            res = static_cast<long> (first) * static_cast<long> (second);
            if (res > INT_MAX || res < INT_MIN)
                throw std::runtime_error("Error: result overflow or underflow");
            break;
        case '/':
            res = static_cast<long> (first) / static_cast<long> (second);
            if(second == 0)
                throw std::runtime_error("Error: division by 0");
            if (res > INT_MAX || res < INT_MIN)
                throw std::runtime_error("Error: result overflow or underflow");
            break;

        default:
            throw std::runtime_error("Error: unknown operator");
    }
    _stack.push(static_cast<int>(res));
}