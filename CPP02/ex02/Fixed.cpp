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

Fixed::Fixed(const int val){
    std::cout << "Int constructor called" << std::endl;
    _fixed_point_nb = val << _fract_bits; /*shift left by 8 bits*/
}

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

// Overloaded Comparison Operators
bool	Fixed::operator>(Fixed fixed) const{
        return this->toFloat() > fixed.toFloat(); 
}

bool    Fixed::operator<(Fixed fixed) const{
        return this->toFloat() < fixed.toFloat(); 
}

bool    Fixed::operator>=(Fixed fixed) const{
        return this->toFloat() >= fixed.toFloat();
}

bool    Fixed::operator<=(Fixed fixed) const{
        return this->toFloat() <= fixed.toFloat();
}

bool    Fixed::operator==(Fixed fixed) const{
        return this->toFloat() == fixed.toFloat();
}

bool    Fixed::operator!=(Fixed fixed) const{
        return this->toFloat() != fixed.toFloat();
}

// Arithmetic operators
Fixed    Fixed::operator+(Fixed fx) const{
        return this->toFloat() + fx.toFloat(); 
}

Fixed    Fixed::operator-(Fixed fx) const{
        return this->toFloat() - fx.toFloat(); 
}

Fixed    Fixed::operator*(Fixed fx) const{
        return this->toFloat() *  fx.toFloat();
}

Fixed    Fixed::operator/(Fixed fx) const{
        return this->toFloat() / fx.toFloat();
}

//on modifie l objet et on retourne une ref sur l objet modifie
Fixed&    Fixed::operator--(){
    _fixed_point_nb -= 1;
    return *this;
}

// Pré (++x/--x): retourne une référence sur l’objet déjà modifié.
Fixed&    Fixed::operator++(){
    _fixed_point_nb += 1;
    return *this;
}
//on sauvergarde une copie on modifie l objetpuis on retourne l ancienne val
Fixed    Fixed::operator--(int){
    Fixed tmp = *this;
    --this->_fixed_point_nb;
    return tmp;
}

//Post (x++/x--): retourne une copie de l’ancienne valeur, puis modifie l’objet.
Fixed    Fixed::operator++(int){
    Fixed tmp = *this;
    ++this->_fixed_point_nb;
    return tmp;
}

Fixed &Fixed::min(Fixed &first, Fixed &second){
	if (first.toFloat() <= second.toFloat())
		return first;
	else	
		return second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second){
	if (first.toFloat() >= second.toFloat())
		return first;
	else	
		return second;
}

const	Fixed &Fixed::max(Fixed const &first, Fixed const &second){
	if (first.toFloat() >= second.toFloat())
		return first;
	else	
		return second;
}

const	Fixed &Fixed::min(Fixed const &first, Fixed const &second){
	if (first.toFloat() <= second.toFloat())
		return first;
	else	
		return second;
}