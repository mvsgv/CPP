#include "Fixed.hpp"
/*
- Objectif:
  - Contrôler précisément comment un objet se crée, se copie, s’assigne et se détruit.
  - Garantir un code sûr avec les ressources (mémoire, fichiers, sockets): éviter double delete, fuites, comportements indéfinis.
  - Assurer un comportement prévisible et portable (déterminisme).

- Pourquoi utile:
  - En définissant ces 4 fonctions, on impose la bonne sémantique de copie (copie profonde, partage contrôlé, interdiction si besoin).
  - Indispensable pour que la classe fonctionne bien avec les conteneurs

- Quand c’est appelé:
  - Constructeur de copie: lors d’une création à partir d’un autre objet (initialisation, passage/retour par valeur).
  - Opérateur d’affectation: quand on remplace le contenu d’un objet déjà existant.
  - Destructeur: à la fin de vie (sortie de scope, delete).
  - Constructeur par défaut: création sans paramètres.
*/
const int Fixed::_fract_bits = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    _fixed_point_nb = 0;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    _fixed_point_nb = copy._fixed_point_nb;
}

Fixed& Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fixed_point_nb = other._fixed_point_nb; 
    }
    return (*this);
}

//sert a retourner la valeur brute interne le const garanti qu il ne modifie pas l objet
int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point_nb;
}

//sert a fixer la valeur brute du nombre a virgule fixe
void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point_nb = raw;
}