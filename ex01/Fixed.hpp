/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:49:24 by eberger           #+#    #+#             */
/*   Updated: 2023/05/31 20:04:53 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

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

private:
	int			_value;
	static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &strm, Fixed const &obj);

#endif
