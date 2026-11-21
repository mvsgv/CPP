#include "Serialization.hpp"

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
    //Convertit l’adresse mémoire du pointeur ptr en un entier non signé (uintptr_t).
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
    //Convertit l’entier brut raw en pointeur vers Data.
}