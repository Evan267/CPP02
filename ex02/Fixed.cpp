/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:52:29 by eberger           #+#    #+#             */
/*   Updated: 2023/06/02 18:09:44 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
	return ;
}

Fixed::Fixed(const int value)
{
	this->setRawBits(value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	this->setRawBits((int)roundf(value * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed&	Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->_value = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const value)
{
	this->_value = value;
}

float	Fixed::toFloat(void) const
{
	float	value_float;

	value_float = (float)this->getRawBits() / (1 << this->_fractionalBits);
	return (value_float);
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream &strm, Fixed const &obj)
{
	strm << obj.toFloat();
	return (strm);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	ret(this->toFloat() + other.toFloat());
	
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	ret(this->toFloat() - other.toFloat());
	
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	ret(this->toFloat() * other.toFloat());
	
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	ret(this->toFloat() / other.toFloat());
	
	return (ret);
}

Fixed	& Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed	& Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret = *this;

	this->_value += 1;
	return (ret);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret = *this;

	this->_value -= 1;
	return (ret);
}

Fixed	Fixed::min(Fixed &first_value, Fixed &second_value)
{
	if (first_value < second_value)
		return (first_value);
	return (second_value);
}

const Fixed	Fixed::min(const Fixed &first_value, const Fixed &second_value)
{
	if (first_value < second_value)
		return (first_value);
	return (second_value);
}

Fixed	Fixed::max(Fixed &first_value, Fixed &second_value)
{
	if (first_value > second_value)
		return (first_value);
	return (second_value);
}

const Fixed	Fixed::max(const Fixed &first_value, const Fixed &second_value)
{
	if (first_value > second_value)
		return (first_value);
	return (second_value);
}
