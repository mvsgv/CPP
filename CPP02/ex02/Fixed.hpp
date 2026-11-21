#pragma once

#include <cmath>
#include <iostream>

class Fixed{
    private:
        int _fixed_point_nb;
        static const int _fract_bits;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed &other);

        //Set
        void setRawBits( int const raw );
        //get
        int getRawBits( void ) const;
        
        //new constructor
        Fixed(const int val);
        Fixed(const float val);
        
        //Overload comparison operators
        bool    operator>(Fixed fixed) const;
        bool    operator<(Fixed fixed) const;
        bool    operator>=(Fixed fixed) const;
        bool    operator<=(Fixed fixed) const;
        bool    operator==(Fixed fixed) const;
        bool    operator!=(Fixed fixed) const;
        
        //4 arithmetic operators: +, -, *, /
        Fixed    operator+(Fixed fx) const;
        Fixed    operator-(Fixed fx) const;
        Fixed    operator*(Fixed fx) const;
        Fixed    operator/(Fixed fx) const;
        
        //4 increment/decrement
        Fixed&    operator++();     //++x
        Fixed     operator++(int);  //x++
        Fixed&    operator--();     //--x
        Fixed     operator--(int);  //x--

        //public overloaded member functions
        float       toFloat(void) const;
        int         toInt(void) const;
        static      Fixed &min(Fixed &first, Fixed &second);
        static      Fixed &max(Fixed &first, Fixed &second);
        static const    Fixed &max(Fixed const &first, Fixed const &second);
        static const    Fixed &min(Fixed const &first, Fixed const &second);
    };
    std::ostream& operator<<(std::ostream& out, const Fixed& fx);