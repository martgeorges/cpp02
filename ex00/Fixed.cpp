/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:54:50 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/25 10:17:18 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_fract_bits_value(8);

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
//opérateur de copie
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

//surcharge de l'opérateur d'affectation
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

//fonction qui retourne la valeur du nombre a virgule sans la convertir
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_value); 
}

//fonction d'initialisation de la valeur du nombre
void Fixed::setRawBits(int const unprocessedValue) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = unprocessedValue;
}