/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:33:18 by eberger           #+#    #+#             */
/*   Updated: 2023/06/03 11:25:41 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(3, 0);
	Point	c(0, 3);

	Point	d(1, 1);
	Point	e(3, 3);
	
	if (bsp(a, b, c, d))
		std::cout << "Le point d est bien présent dans le triangle" << std::endl;
	else
		std::cout << "Le point d n'est pas présent dans le triangle" << std::endl;
	if (bsp(a, b, c, e))
		std::cout << "Le point e est bien présent dans le triangle" << std::endl;
	else
		std::cout << "Le point e n'est pas présent dans le triangle" << std::endl;

	return 0;
}
