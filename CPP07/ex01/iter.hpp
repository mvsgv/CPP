#pragma once
#include <iostream>
#include <cstddef>

template<typename T> 
void iter(T *array, const size_t length, void (*parcour)(T&)){
    if (!array || length == 0 || !parcour){
        std::cerr << "Error" << std::endl;
        return;
    }
    for(size_t i = 0; i < length; i++){
        parcour(array[i]);
    }
};

template<typename T> 
void iter(const T *array, const size_t length, void (*parcour)(const T&)){
    if (!array || length == 0 || !parcour){
        std::cerr << "Error" << std::endl;
        return;
    }
    for(size_t i = 0; i < length; i++){
        parcour(array[i]);
    }
};

