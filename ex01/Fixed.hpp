/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:22 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/24 10:35:33 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    static int _fract_bits_value;
    int _value;
public:
    Fixed();
    Fixed(const int i_val);
    Fixed(const float f_val);
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed & operator = (const Fixed &other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int toInt( void ) const;
    float toFloat( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & fixed);

#endif