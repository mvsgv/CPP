#include "Dog.hpp"
#include "Cat.hpp"
#include "Polymorphism.hpp"
#include "WrongAnimal.hpp"
#include  "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    WrongAnimal *animal = new WrongCat();
        animal->makeSound(); // Should call WrongCat's makeSound() if polymorphism is set up correctly
delete animal;
return 0;
}