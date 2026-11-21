#pragma once

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal& copy);
        Animal(std::string type);
        Animal &operator=(const Animal &target);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
};

//polymorpfisme dynamique ?
/*
Poly = plusieurs  
Morphisme = formes ->   Une même interface, plusieurs comportements
dans mon main jai le même type de pointeur -> Animal
mais des objets différents (Dog, Cat) ce qui me donne un comportements différent
Sans virtual (pas de polymorphisme):
Sans polymorphisme:
- Tous diraient "Different animals make different sounds." 
- Les destructeurs de Dog/Cat ne seraient pas appelés →memory leaks
Avec polymorphisme:
- Dog dit "Woof", Cat dit "Meow" 
- Les bons destructeurs sont appelés (Dog puis Animal, Cat puis Animal) 
*/