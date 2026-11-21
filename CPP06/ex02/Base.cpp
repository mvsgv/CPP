#include "Base.hpp"

Base::~Base(){}

Base * generate(void){
    srand(time(0));
    int random = rand() % 3;
        if (random == 0)
                return new A();
        else if (random == 1)
                return new B();
        else    
            return new C();
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "Type object pointed is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type object pointed is B " << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type object pointed is C" << std::endl;
    else
       std::cout << "Dynamic cast failed." << std::endl; ;
}

void identify(Base& p){
    try{
        A& castA = dynamic_cast<A&>(p);
            std::cout << "Type object pointed is A" << std::endl;
        (void)castA;
    }catch(std::bad_cast&){}
    try{
        B& castB = dynamic_cast<B&>(p);
            std::cout << "Type object pointed is B" << std::endl;
        (void)castB;
    }catch(...){}
    try{
        C& castC = dynamic_cast<C&>(p);
         std::cout << "Type object pointed is C" << std::endl;
        (void)castC;
    }catch(...){}
}