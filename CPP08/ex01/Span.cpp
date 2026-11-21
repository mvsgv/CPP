#include "Span.hpp"

Span::Span() : _N(0){
    std::cout << "Span constructor called " << std::endl;
}

Span::Span(unsigned int N){
    _N = N;
}
Span::Span(const Span &copy){
    *this = copy;
}
Span &Span::operator=(const Span &target){
    if (this != &target){
        _N = target._N;
        _container = target._container;
    }
    return *this;
}
Span::~Span(){}

void    Span::addNumber(int n){
    if (_container.size() >= _N)
        throw std::runtime_error("Container already full");
    _container.push_back(n);
}

int     Span::shortestSpan(){
    if (_container.size() < 2)
        throw std::runtime_error("Error: missing elements");

    std::vector<int> tmp = _container;
    std::sort(tmp.begin(), tmp.end());
    std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());

    int min = *std::min_element(tmp.begin() + 1, tmp.end());
    return min; 
}

int     Span::longestSpan(){
    if (_container.size() < 2)
        throw std::runtime_error("Error: missing elements");

    int min = *std::min_element(_container.begin(), _container.end());
    int max = *std::max_element(_container.begin(), _container.end());

    return max - min;
}

