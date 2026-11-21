#pragma once
# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <list>
# include <algorithm>

template <typename T> 
typename T::iterator easyfind(T &array, int value){
    
    typename T::iterator iterator;

    iterator = std::find(array.begin(), array.end(), value);
    if (iterator == array.end()){
            std::cerr << "Unable to find the value: ("  << value  << ")" << std::endl;
            throw std::runtime_error("No value found in container");
        }
        return (iterator);
}