/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:16:44 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/13 09:17:15 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**************constructors*********************************/

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &src) : _value(src._value) {}

Fixed::Fixed(const int value)
{
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _value = roundf(value * (1 << _fractionalBits));
}

/**************destructor**********************************/

Fixed::~Fixed() {}

/**************affectattion operator**********************/

Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        _value = src.getRawBits();
    return *this;
}

/**************arithmetic operators**********************/

Fixed Fixed::operator+(const Fixed &src) const
{
    return Fixed(toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return Fixed(toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return Fixed(toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return Fixed(toFloat() / src.toFloat());
}

/**************comparison operators**********************/

bool Fixed::operator>(const Fixed &src) const
{
    return _value > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const
{
    return _value < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const
{
    return _value >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const
{
    return _value <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const
{
    return _value == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const
{
    return _value != src.getRawBits();
}

/**************increment and decrement operators**********************/

Fixed &Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

/**************member functions***********************************/

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

 const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

/**************non-member functions***********************************/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}