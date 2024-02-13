/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:12:20 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/13 11:23:34 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x = point.getX();
    Fixed const y = point.getY();
    std::cout << "x: " << x << " y: " << y << std::endl;
    

    Fixed const x1 = a.getX();
    Fixed const y1 = a.getY();
    Fixed const x2 = b.getX();
    Fixed const y2 = b.getY();
    Fixed const x3 = c.getX();
    Fixed const y3 = c.getY();
    std::cout << "x1: " << x1 << " y1: " << y1 << std::endl;
    std::cout << "x2: " << x2 << " y2: " << y2 << std::endl;
    std::cout << "x3: " << x3 << " y3: " << y3 << std::endl;

    Fixed const a1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
    Fixed const a2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
    Fixed const a3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);
    std::cout << "a1: " << a1 << std::endl;
    std::cout << "a2: " << a2 << std::endl;
    std::cout << "a3: " << a3 << std::endl;

    if (a1 >= 0 && a2 >= 0 && a3 >= 0)
    {
        std::cout << "they're all positive so" << std::endl;
        return true;
    }  
    if (a1 <= 0 && a2 <= 0 && a3 <= 0)
    {
        std::cout << "they're all negative so" << std::endl;
        return true;
    }
    std::cout << "they're not all positive or negative so" << std::endl;
    return false;
}

int main()
{
    Point a(0.1f, 0.6f); 
    Point b(0, 4); 
    Point c(4, 0);
    Point point(0.6f, 2);
    
    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle" << std::endl;
    else
        std::cout << "The point is outside the triangle" << std::endl;
    return 0;
}