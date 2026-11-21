#pragma once 
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
    private :
        ScalarConverter();
    public:
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &target);
        ScalarConverter(const ScalarConverter &copy);
        
        static void convert(std::string type);
        static std::string isSpecial(const std::string &str);
        static void conversion(int i, float f, double d);
        
        static void checkforspecials(std::string special);
        static bool ischar(const std::string &c);
        static bool isint(const std::string &i);
        static bool isfloat(const std::string &f);
        static bool isdouble(const std::string &d);
    };