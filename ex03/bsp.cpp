/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:44:47 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/23 11:59:43 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <math.h>
#include <limits>

float area(Point const a, Point const b, Point const c)
{
    return (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
            b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
            c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) /
           2;
}

bool isOnTheLine(Point const a, Point const b, Point const c)
{
    float area_abc = area(a, b, c);
    if (area_abc == 0)
        return true;
    return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float abc = std::abs(area(a, b, c));
    float abp = std::abs(area(a, b, point));
    float acp = std::abs(area(a, c, point));
    float bcp = std::abs(area(b, c, point));

    if (isOnTheLine(a, b, c) || isOnTheLine(a, b, point) || isOnTheLine(a, c, point) || isOnTheLine(b, c, point))
        return false;

    float sumAreas = abp + acp + bcp;
    bool isInside = std::abs(abc - sumAreas) < std::numeric_limits<float>::epsilon();

    if (isInside && sumAreas > 0 && !isOnTheLine(a, b, c))
        return true;
    return false;
}
