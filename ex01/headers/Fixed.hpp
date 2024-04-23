#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int fp_nb;
        static const int fr_bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &obj);
        Fixed(const int nb_i);
        Fixed(const float nb_f);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        int getFrBits(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
