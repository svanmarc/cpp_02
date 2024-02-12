/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:44 by svanmarc          #+#    #+#             */
/*   Updated: 2024/02/12 18:59:15 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int					_value;
    static const int	_fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &src);
    ~Fixed();

    Fixed &operator=(const Fixed &src);

    int		getRawBits(void) const;
    void	setRawBits(int const raw);
};

#endif