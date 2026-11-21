#include "iter.hpp"

void    printInt(int &i){
    std::cout << i << std::endl;
}
void    printString(std::string &str){
    std::cout << str << std::endl;
}

void    printconstInt(const int &i){
    std::cout << i << std::endl;
}
void    printconstString(const std::string &str){
    std::cout << str << std::endl;
}

int main(){

    std::cout << "Printing int\n";
    int array_int[] = {1, 2, 3, 4, 5, 6};

    int i = sizeof(array_int) / sizeof(array_int[0]);
    ::iter(array_int, i, printInt);
    
    std::cout <<"Printing string\n";
    std::string arr_str[] = {"I", "do", "iterate", "as", "expected"};
    
    ::iter(arr_str, 5, printString);
    for (int i = 0; i < 3; i++){
		std::cout << arr_str[i] << std::endl;
    }

    std::cout << "Printing const int\n";
    const int CT[] = {10,11,12,13};
    ::iter(CT, sizeof(CT)/sizeof (CT[0]), printconstInt);

    std::cout << "Printing const string\n";
    const std::string CS[] = {"consts", "do", "iterate", "as", "expected"};
    ::iter(CS, sizeof(CS)/sizeof (CS[0]), printconstString);
}
