#include "Serialization.hpp"

int main(){
    Data human;
    human.age = 25;


    
    std::cout << "Age adddres:" << &human << std::endl;
    std::cout << "Age value :" << human.age << std::endl;
    
    //serialisation
    uintptr_t raw = Serializer::serialize(&human);
    std::cout << "Serialized data : "<< raw <<std::endl;

    //deserialisation
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserializer data address: "<< ptr <<std::endl;
    std::cout << "Deserializer data value: "<< ptr->age <<std::endl;

    if (ptr == &human)
        std::cout << "Succes: deserialization worked" << std::endl;
    else
        std::cout << "Failure :(" << std::endl;

}