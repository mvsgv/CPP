#include "Span.hpp"

int main()
{
    std::cout << "1 testing" << std::endl;
    Span sp = Span(15);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: "<< sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;


    std::cout << "\n2 testing" << std::endl;
    Span sp1 = Span(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(i);

    sp1.addManyNumbers(numbers.begin(), numbers.end());

    std::cout << "Shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp1.longestSpan() << std::endl;


    std::cout <<"\n3 testing: empty span" << std::endl;
   
    Span sp2(10);
    try {
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    Span sp3(10);
    sp3.addNumber(42);
    try {
        std::cout << sp3.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {

        std::cout << "\n4 testing only one nb: Caught: " << e.what() << std::endl;
    }


    Span sp4(3);
            std::cout << "\n5 testing full container: "<< std::endl;
    try{
    sp4.addNumber(1);
    sp4.addNumber(2);
    sp4.addNumber(3);
    sp4.addNumber(4); 
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}