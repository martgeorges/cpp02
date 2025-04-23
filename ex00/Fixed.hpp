/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:55:06 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/21 14:22:00 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int _value;
    static int  bits_value;
public:
    Fixed();
    //Fixed(const Fixed &other);
    ~Fixed();
    //Fixed & operator = (const Fixed &other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif