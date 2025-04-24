/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:11:35 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/24 19:33:11 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

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

        bool operator> (Fixed const &other) const;
        bool operator< (Fixed const &other) const;
        bool operator>=(Fixed const &other) const;
        bool operator<=(Fixed const &other) const;
        bool operator==(Fixed const &other) const;
        bool operator!=(Fixed const &other) const;

        Fixed operator+ (Fixed const &other) const;
        Fixed operator- (Fixed const &other) const;
        Fixed operator/ (Fixed const &other) const;
        Fixed operator* (Fixed const &other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed &a, Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& min(Fixed const &a, Fixed const &b);
        static const Fixed& max(Fixed const &a, Fixed const &b);

};

std::ostream & operator<<( std::ostream & o, Fixed const & fixed);

#endif