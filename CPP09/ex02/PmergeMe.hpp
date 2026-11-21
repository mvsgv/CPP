#pragma once 

#include <deque>
#include <vector>
#include <cstddef>
#include <iterator>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/time.h>

class PmergeMe{ 
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &target);
        ~PmergeMe();

        void    run(int ac, char **av);
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        void    sortVector(std::vector<int> &container);
        void    sortDeque(std::deque<int> &container);
        bool  isValidInput(const std::string& str);

        //bool    parseInput(int ac, char **av);
};