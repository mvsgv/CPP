#pragma once 
#include <map>
#include <string>
#include <iostream>
#include <errno.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>

class BitcoinExchange {
    public:
        std::map<std::string, float>_BitcoinPriceTag;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &target);
        ~BitcoinExchange();

        void    printExchangeCalculations(std::string value);
        bool    validDate(std::string date);
        int     parseCSV(std::string filemane);
};

