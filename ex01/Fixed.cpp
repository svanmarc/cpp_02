/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:39:26 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/20 15:30:41 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

// here we shift the value to the left by 8 to get the fixed point value
Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

// here we round the value to the nearest integer (roundf)
// and then we shift the value to the left by 8 to get the fixed point value (value * 256)
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// here "this != &src" is to avoid self-assignment and to avoid deleting the object before copying it
// if we delete the object before copying it, we will have a segfault
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        _value = src.getRawBits();
    return *this;
}

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
    return (float)_value / (1 << _fractionalBits); // value / 256
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits; // shift right to convert back to int
}

// here we overload the operator << to display the value of the object
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}