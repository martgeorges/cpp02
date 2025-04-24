/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:06 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/24 10:35:36 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_fract_bits_value(8);

//constructeur
Fixed::Fixed():_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
//constructeur INT
//décalage vers la gauche pour mettre le int en valeur entier
Fixed::Fixed(int const i_val)
{
    std::cout << "Int constructor called" << std::endl;
    _value = i_val << _fract_bits_value;
}
//constructeur FLOAT
//décalage vers la gauche pour mettre le float en valeur entier
Fixed::Fixed(float const f_val)
{
    std::cout << "Float constructor called" << std::endl;
    _value = (int)roundf(f_val * (1 << _fract_bits_value));
}
//destructeur
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
//constructeur copy
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}
//operateur d'assignation
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (_value); 
}
//fonction qui sert a faire l'inverse passer f_val a [f_val,...]
float Fixed::toFloat( void ) const {
    return (float)_value / (float)(1 << _fract_bits_value);
}
//fonction qui sert a faire l'inverse -> passer i_val a [i_val,...]
int Fixed::toInt( void ) const {
    return (int)(_value >> _fract_bits_value);
}

std::ostream & operator<<( std::ostream & o, Fixed const & fixed){
    o << fixed.toFloat();
    return (o);
}