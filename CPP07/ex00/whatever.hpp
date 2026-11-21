#pragma once 
#include <iostream>
/*template <typename T> : Utilisé dans la déclaration d'un template pour spécifier
que T est un type générique (un substitut pour int, double, une classe, etc.).
typename = class*/
template<typename T> void swap(T &x, T &y){
   T tmp;
   tmp = x;
   x = y;
   y = tmp;
}

template<typename T> const T &min(T &x, T &y){
   return x < y ? x : y;
}

template<typename T> const T &max(T &x, T &y){
   return x > y ? x : y;
}