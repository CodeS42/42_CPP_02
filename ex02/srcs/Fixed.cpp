#include "../headers/Fixed.hpp"

Fixed::Fixed() : fp_nb(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    // std::cout << "Copy constructor called" << std::endl;
    setRawBits(obj.getRawBits());
}

Fixed::Fixed(const int nb_i)
{
    // std::cout << "Int constructor called" << std::endl;
    setRawBits(nb_i * (1 << getFrBits()));
}

Fixed::Fixed(const float nb_f)
{
    // std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(nb_f * (1 << getFrBits())));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (fp_nb);
}

void Fixed::setRawBits(int const raw)
{
    fp_nb = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(getRawBits()) / (1 << getFrBits()));
}

int Fixed::toInt(void) const
{
    return (getRawBits() / (1 << getFrBits()));
}

int Fixed::getFrBits(void) const
{
    return (fr_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
    this->setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed& Fixed::operator--()
{
    this->setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    ++(*this);
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    
    --(*this);
    return (tmp);
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if (obj1 < obj2)
        return (obj1);
    return (obj2);
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 < obj2)
        return (obj1);
    return (obj2);
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj1);
    return (obj2);
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj1);
    return (obj2);
}
