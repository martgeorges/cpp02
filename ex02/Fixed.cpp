/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:11:45 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/25 10:16:27 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::_fract_bits_value(8);

//constructeur
Fixed::Fixed():_value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

//constructeur INT
Fixed::Fixed(int const i_val)
{
    //std::cout << "Int constructor called" << std::endl;
    _value = i_val << _fract_bits_value;
}

//constructeur FLOAT
Fixed::Fixed(float const f_val)
{
    //std::cout << "Float constructor called" << std::endl;
    _value = (int)roundf(f_val * (1 << _fract_bits_value));
}

//destructeur
Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

//constructeur copy
Fixed::Fixed(const Fixed &copy) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

//operateur d'assignation
Fixed& Fixed::operator=(const Fixed &other) {
    //std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const unprocessedValue) {
    //std::cout << "setRawBits member function called" << std::endl;
    _value = unprocessedValue;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (_value); 
}

float Fixed::toFloat( void ) const {
    return (float)_value / (float)(1 << _fract_bits_value);
}

//fonction qui sert a faire l'inverse -> passer i_val a [i_val,...]
int Fixed::toInt( void ) const {
    return (int)(_value >> _fract_bits_value);
}

//6 opérateur de comparaison bool car c'est soit l'un ou l'autre
bool Fixed::operator> (Fixed const &other) const {
    return getRawBits() > other.getRawBits();
}

bool Fixed::operator< (Fixed const &other) const {
    return getRawBits() < other.getRawBits();
}

bool Fixed::operator>= (Fixed const &other) const {
    return getRawBits() >= other.getRawBits();
}

bool Fixed::operator<= (Fixed const &other) const {
    return getRawBits() <= other.getRawBits();
}

bool Fixed::operator== (Fixed const &other) const {
    return getRawBits() == other.getRawBits();
}

bool Fixed::operator!= ( Fixed const &other) const {
    return getRawBits() != other.getRawBits();
}

//4 opérateurs arithmétiques 
Fixed Fixed::operator+ (Fixed const &other) const {
    Fixed result;
    result.setRawBits(getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator- (Fixed const &other) const {
    Fixed result;
    result.setRawBits(getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator/ (Fixed const &other) const {
    Fixed result;
    result.setRawBits(getRawBits() / other.getRawBits() << _fract_bits_value);
    return result;
}

Fixed Fixed::operator* (Fixed const &other) const {
    Fixed result;
    result.setRawBits(getRawBits() * other.getRawBits() >> _fract_bits_value);
    return result;
}

//pré incrément
//opérateur d'incrémentation ->retourne la valeur après incrémentation
Fixed& Fixed::operator++() {
    _value++;
    return *this; 
}

//post incrément
//opérateur d'incrémentation -> copie, incrémente et retourne la valeur copiée avant incrémentation
Fixed Fixed::operator++(int) {
    Fixed copy(*this);
    _value++;
    return copy;
}

//pré décrémentation
//opérateur de décrémentation -> retourne la valeur après décrémentation
Fixed& Fixed::operator--() {
    _value--;
    return *this;
}

//post décrémentation
//opérateur de décrémentation -> copie, décrémente et retourne la valeur copiée avant décrémentation
Fixed Fixed::operator--(int) {
    Fixed copy(*this);
    _value--;
    return copy;
}

//fonction qui retourne le plus petit -> statique mais pas const
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}
//fonction qui retourne le plus grand -> statique mais pas const
Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
    if (a > b)
        return a;
    return b;
}

std::ostream & operator<<( std::ostream & o, Fixed const & fixed){
    o << fixed.toFloat();
    return (o);
}