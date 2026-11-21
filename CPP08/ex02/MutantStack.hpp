#pragma once 

#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
#include <ostream>


template <typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack(){}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
        MutantStack &operator=(const MutantStack &target){
            if (this != &target)
                std::stack<T>::operator=(target);
            return *this;
        }
        ~MutantStack(){}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(){return this->c.begin();}
        iterator end() {return this->c.end();}
};