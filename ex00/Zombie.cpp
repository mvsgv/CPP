/*Zombie::Zombie(std::string name) : name(name) {
  ^class  ^constructor      ^parameter  ^initializer list
}
1. Object Initialization:
- When you create Zombie zom("Foo") C++ needs to initialize the object
- The constructor tells C++ how to set up the object with the given data
- Without a constructor, C++ doesn't know what to do with "Foo"

2. Setting Private Members:
- name is private, so you can't access it directly from main
- The constructor is the only way to set name when creating the object

Parts explained:
- Zombie::Zombie - This is the constructor for class Zombie
- (std::string name) - Parameter: the name you pass when creating the object
- : name(name) - Initializer list: sets this->name = name
- {} - Constructor body (empty here, but could contain more code)
*/

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "Class created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
