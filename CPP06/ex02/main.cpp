#include "Base.hpp"

int main(){
    std::srand(static_cast<unsigned int>(time(0)));	
    Base *base = generate();
    identify(base);
    identify(*base);
    // Base* a1 = NULL;
    // a1 = dynamic_cast<A*>(a1);
    // std::cout << a1 << 
    // a1->print();
}