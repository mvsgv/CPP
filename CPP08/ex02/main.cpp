# include "MutantStack.hpp"

int main()
{
    std::cout << "1st TEST : main from subject pdf " << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    

    std::cout << "\n2nd test : empty stack iteration" << std::endl;
    MutantStack<int> m;

    MutantStack<int>::iterator it1 = m.begin();
    MutantStack<int>::iterator ite1 = m.end();

    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }


   std::cout << "\n3rd TEST: massive push" << std::endl;
    MutantStack<int> m1;

    for (int i = 0; i < 1000000; i++)
        m1.push(i);

    std::cout << m1.top() << std::endl;
}
