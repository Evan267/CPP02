/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:52:29 by eberger           #+#    #+#             */
/*   Updated: 2023/05/31 20:15:50 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout <<  "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(value * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
