#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

template<class T> 
class Array{
    private:
        size_t _size;
        T* _data;
    public:
        Array() : _size(0), _data(NULL){};
        Array(unsigned int n) : _size(n){
            _data = new T[n]();
        }

        Array(const Array& copy) : _size(copy._size){
            _data = new T[_size];
            for (size_t i = 0; i < _size; i++){
                _data[i] = copy._data[i];
            }
        }
        /*  - Vérifier l’auto-affectation.
            - Supprimer l’ancien tableau.
            - Allouer un nouveau tableau de la bonne taille.
            - Copier chaque élément.*/
        Array& operator=(const Array& target){
            if (this != &target){
                delete[] _data;
                _size = target._size;
                _data = new T[_size];
                for (size_t i = 0; i < _size; i++){
                    _data[i] = target._data[i];
                }
            }
            return *this;
        }
        
        ~Array(){
            delete[] _data;
        }
        size_t size()const{
            return _size;
        }
/* 
1. Ajouter l’opérateur d’indexation `operator[]` dans ta classe [`Array`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22external%22%3A%22file%3A%2F%2F%2FUsers%2Fmariamevissargova%2FDesktop%2FCPP07%2Fex02%2FArray.hpp%22%2C%22path%22%3A%22%2FUsers%2Fmariamevissargova%2FDesktop%2FCPP07%2Fex02%2FArray.hpp%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A7%2C%22character%22%3A6%7D%5D "ex02/Array.hpp").
2. Il doit retourner une référence à l’élément demandé.
3. Prévoir une version const et non-const.
*/
        const T& operator[](size_t index)const{
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _data[index];
        }
        T& operator[](size_t index){
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _data[index];
        }
};



#endif