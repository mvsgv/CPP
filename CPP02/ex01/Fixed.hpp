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
        Fixed(const Fixed& copy);//constructeur de copie
        Fixed& operator=(const Fixed &other);
        /*Setter an getter*/
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        /*new constructor*/
        Fixed(const int val);
        Fixed(const float val);

        /*conversion function*/
        float    toFloat(void) const;
        int     toInt(void) const;
        
    };

    std::ostream& operator<<(std::ostream& out, const Fixed& fx);