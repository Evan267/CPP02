/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:49:24 by eberger           #+#    #+#             */
/*   Updated: 2023/06/02 18:10:10 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &obj);
	~Fixed(void);
	Fixed&	operator=(const Fixed &obj);
	int	getRawBits(void) const;
	void	setRawBits(int const value);
	float	toFloat(void) const;
	int	toInt(void) const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed	min(Fixed &first_value, Fixed &second_value);
	static const Fixed	min(const Fixed &first_value, const Fixed &second_value);
	static Fixed	max(Fixed &first_value, Fixed &second_value);
	static const Fixed	max(const Fixed &first_value, const Fixed &second_value);

private:
	
	int			_value;
	static const int	_fractionalBits = 8;

};

std::ostream& operator<<(std::ostream &strm, Fixed const &obj);

#endif
