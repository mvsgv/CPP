#pragma once 

#include <iostream>

class Fixed{
    private:
        int _fixed_point_nb;
        static const int _fract_bits;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& copy);
        Fixed&  operator=(const Fixed &other);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
    };