/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:49:24 by eberger           #+#    #+#             */
/*   Updated: 2023/05/30 23:16:18 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(const Fixed &obj);
	~Fixed(void);
	Fixed&	operator=(const Fixed &obj);
	int	getRawBits(void) const;
	void	setRawBits(int const value);

private:
	
	int			_value;
	static const int	_fractionalBits = 8;

};

#endif
