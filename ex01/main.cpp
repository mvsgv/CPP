#include "Zombie.hpp"

int main(){

    int N = 10;
    Zombie *zomHorde = zombieHorde(N, "Horde");
    for(int i = 0; i < N; i++){
        zomHorde[i].announce();
    }
    delete[] zomHorde;
    return 0;
}