/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:17:33 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/13 10:20:07 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(float const floatX, float const floatY);
	Point(Point const &src);;
	~Point();
	Point &operator=(Point const &rhs);
	Fixed getX() const;
	Fixed getY() const;
};


#endif