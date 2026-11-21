#pragma once 

#include <iostream>
#include <stdint.h>

class Data{
    public:
        int age;
};

class Serializer{
    private: 
        Serializer();
        ~Serializer();
        Serializer& operator=(const Serializer &target);
        Serializer(const Serializer &copy);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};