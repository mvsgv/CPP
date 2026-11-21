#pragma once

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <numeric>

class Span{
    private:
        unsigned int _N;    
        std::vector<int> _container;
    public:
        Span();    
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &target);
        ~Span();
        
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();


        template <typename Iterator>
        void    addManyNumbers(Iterator first, Iterator last){
        if (_container.size() + std::distance(first, last) > _N)
            throw std::runtime_error("Not enough space in Span");

        _container.insert(_container.end(), first, last);
    }

};
