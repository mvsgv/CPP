#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    Array<int> empty;
    if (empty.size() != 0)
    {
        std::cerr << "empty array size should be 0" << std::endl;
        return 1;
    }

    Array<int> numbers(5);
    if (numbers.size() != 5)
    {
        std::cerr << "unexpected array size" << std::endl;
        return 1;
    }
    for (size_t index = 0; index < numbers.size(); ++index)
    {
        if (numbers[index] != 0)
        {
            std::cerr << "elements must be default-initialized" << std::endl;
            return 1;
        }
    }

    numbers[0] = 42;
    numbers[1] = 7;

    const Array<int> constantCopy(numbers);
    if (constantCopy[0] != 42 || constantCopy[1] != 7)
    {
        std::cerr << "copy construction failed" << std::endl;
        return 1;
    }

    Array<int> assigned;
    assigned = numbers;
    assigned[0] = 99;
    if (numbers[0] != 42 || assigned[0] != 99)
    {
        std::cerr << "assignment must perform a deep copy" << std::endl;
        return 1;
    }

    try
    {
        numbers[5] = 1;
        std::cerr << "out-of-bounds access did not throw" << std::endl;
        return 1;
    }
    catch (const std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }

    srand(static_cast<unsigned int>(time(NULL)));
    for (size_t index = 0; index < numbers.size(); ++index)
    {
        numbers[index] = rand();
    }

    return 0;
}