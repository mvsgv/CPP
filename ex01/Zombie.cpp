/*
Explication de `Zombie::Zombie()` :

1. Premier `Zombie` = Nom de la classe
- Indique à quelle classe cette méthode appartient

2. Deuxième `Zombie` = Nom du constructeur
- Le constructeur a toujours le même nom que la classe

3. Les `::` = Opérateur de résolution de portée
- Signifie "appartient à" ou "membre de"

Analogie simple :
Personne::Personne()  →  "Le constructeur Personne de la classe Personne"
Voiture::Voiture()    →  "Le constructeur Voiture de la classe Voiture"
Zombie::Zombie()      →  "Le constructeur Zombie de la classe Zombie"
*/

#include "Zombie.hpp"
 //constructeur de la classe zombie
Zombie::Zombie(){
    this->name = "";
}
//destructeur de la classe zombie
Zombie::~Zombie(){
    std::cout << name << " is destroyed" << std::endl;
}
//methode announce de la classe zombie
void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//classe zombie. Sert a definir ou changer un nom
//cette methode accepte uniquement un string 'name' en parametre 
//THIS-> est un pointeur vers l objet actuel 
//= name signifie qu on assigne la valeur du parametre name donc this->name devient ex:"Bob"
//On utilise this-> car on a deux variables avec le meme nom
// le premier etant le param de la fonction et le deuxieme attribut prive de la classe 
// this->name precise qu on parle de l attribut de l objet et nondu parametre
/*ce qui se passe 
name(parametre) = 'Bob'
this->name (attribut) = deveint 'Bob'*/
void Zombie::setName(std::string name){
    this->name = name;
}