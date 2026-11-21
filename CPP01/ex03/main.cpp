/*
- HumanA reçoit une Weapon dans son constructeur → il contient une référence (Weapon&) et sera toujours armé. 
    Ça garantit que l'objet HumanA ne peut pas exister sans arme. Utile quand l'arme est obligatoire dès la création.
- HumanB ne reçoit pas d'arme à la création → il contient un pointeur (Weapon*), 
initialement nullptr, et on peut plus tard lui affecter une arme via setWeapon. 
Ça permet d’avoir des HumanB désarmés et de changer/retirer l’arme dynamiquement.

Conséquences pratiques et règles à respecter
- Référence (HumanA) : doit être initialisée dans la liste d’initialisation du constructeur. 
    Elle ne peut pas être nulle et ne peut pas être réassignée. 
        L’objet Weapon doit vivre plus longtemps que le HumanA (éviter les pointeurs/dangling).
- Pointeur (HumanB) : peut être nullptr, peut être réassigné,
     il faut tester s’il est non nul avant d’appeler weapon->getType(). 
        Encore une fois, s’assurer que l’arme pointée reste valide.

Pourquoi l’exercice ?
- Te faire pratiquer références vs pointeurs, initialisation via liste d’initialisation, 
    tests de nullité et gérer la durée de vie des objets.
- Montrer quand choisir référence (obligation, simplicité) vs pointeur (optionnel, flexible).
*/
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        return 0;
    }
}