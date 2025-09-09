#include "Zombie.hpp"



Zombie* zombieHorde( int N, std::string name ){
    Zombie *ZomHorde = new Zombie[N];
    for(int i = 0; i < N; i++){
        ZomHorde[i].setName(name);
    }
    return ZomHorde;
}