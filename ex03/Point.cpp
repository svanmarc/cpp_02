/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:23:36 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/13 10:35:28 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const floatX, float const floatY) : _x(floatX), _y(floatY) {}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {}

Point::~Point(void) {}

// this is a swallow copy of the object src, so we don't need to do anything
// because the object is already created
// it's just to be conform with the Coplien's form (canonical form)
Point &Point::operator=(Point const &)
{
    return *this;
}

Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}





