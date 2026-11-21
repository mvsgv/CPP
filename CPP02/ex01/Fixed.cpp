/*
stocker 42.75->
Avec les float normaux :
- L'ordinateur stocke ça de manière compliquée (mantisse + exposant)
- Parfois il y a des erreurs : 0.1 + 0.2 ne donne pas exactement 0.3
- C'est lent sur certains processeurs

Avec Fixed-Point :
- On va tricher et utiliser seulement des nombres entiers
- Mais on va faire semblant que c'est un nombre décimal

L'idée:
- Au lieu de stocker directement 42.75
- On va stocker 42.75 × 256 = 10944 (nombre entier)
- Puis quand on veut récupérer 42.75, on fait 10944 ÷ 256 = 42.75

Pourquoi 256 ?
- On a décidé d'utiliser 8 bits pour la partie décimale
- 8 bits peuvent représenter 256 valeurs différentes
- Donc 256 = notre "unité de conversion"

3. Ce que font les NOUVELLES fonctions

Fixed(int value) - Le constructeur depuis entier
En mots : "Prends un nombre entier et transforme-le en format fixed-point"
Exemple : Si je donne 42, ça stocke 42 × 256 = 10752 à l'intérieur

Fixed(float value) - Le constructeur depuis décimal  
En mots : "Prends un nombre décimal et transforme-le en format fixed-point"
Exemple : Si je donne 42.75, ça stocke 42.75 × 256 = 10944 à l'intérieur

toFloat() - Récupérer le décimal
En mots : "Prends la valeur stockée et retransforme-la en nombre décimal normal"
Exemple : Si j'ai 10944 stocké, ça me rend 10944 ÷ 256 = 42.75

toInt() - Récupérer la partie entière
En mots : "Prends la valeur stockée et donne-moi seulement la partie entière"
Exemple : Si j'ai 10944 stocké (qui représente 42.75), ça me rend juste 42

operator<< - L'affichage
En mots : "Quand je fais cout << monFixed, affiche le nombre comme un décimal normal"
Exemple : Ça va utiliser toFloat() pour convertir et afficher 42.75 au lieu de 10944

4. Pourquoi c'est UTILE ?

Performance : Les opérations sur les entiers sont plus rapides que sur les décimaux
Précision : Pas d'erreurs bizarres comme avec les float normaux
Déterminisme : Le même calcul donnera toujours exactement le même résultat

6. Ce qu'il se passe dans mon MAIN

Fixed b(10);           // Stocke 10 × 256 = 2560
Fixed c(42.42f);       // Stocke 42.42 × 256 = 10859

cout << b;             // Affiche 2560 ÷ 256 = 10.0
cout << c;             // Affiche 10859 ÷ 256 = 42.42

b.toInt();             // Retourne 2560 ÷ 256 = 10 (partie entière)
c.toInt();             // Retourne 10859 ÷ 256 = 42 (partie entière)

Fixed-Point = "Faire semblant qu'un entier est un décimal en multipliant/divisant par 256"

3. Pourquoi 8 bits pour les décimales ?
On a décidé de diviser notre nombre entier (32 bits) en deux parties :
┌─────────────────┬─────────────────┐
│  24 bits        │     8 bits      │
│ Partie ENTIÈRE  │ Partie DÉCIMALE │
└─────────────────┴─────────────────┘

8 bits = 256 valeurs possibles pour les décimales
256 = choix optimal entre précision et performance
256 = puissance de 2 → opérations bit super rapides !

8 bits → 256 c'est juste: 2^8 = 256 
*/

#include "Fixed.hpp"

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

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point_nb;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point_nb = raw;
}

/*Conversion int to fixed point
construire un fixed a partir d un entier -> muiltiplier l entier par 2⁸ = 256*/
Fixed::Fixed(const int val){
    std::cout << "Int constructor called" << std::endl;
    _fixed_point_nb = val << _fract_bits; /*shift left by 8 bits*/
}

/*conversion float to fixed point
construire un fixed a partir d un float avec decimale
multiplue le float par 256 puis om arrondi avec roundf pour un avoir l entier brut
Exemple: val=2.75 → 2.75×256=704 → brut=704 → représente ~2.75; val=2.73 → 2.73×256≈699.84 → arrondi à 700.*/
Fixed::Fixed(const float val){
    std::cout << "Float constructor called" << std::endl;
    _fixed_point_nb = roundf(val * (1 << _fract_bits));/*multiplication 2⁸ et arrondissemnt*/
}

float   Fixed::toFloat(void) const {
        return (float)this->_fixed_point_nb / (float)(1 << this->_fract_bits);
}

int     Fixed::toInt(void) const {
        return _fixed_point_nb >> _fract_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fx){
    out << fx.toFloat();
    return out;
}

