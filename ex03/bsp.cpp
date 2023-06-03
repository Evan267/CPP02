/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:53:01 by eberger           #+#    #+#             */
/*   Updated: 2023/06/03 11:26:32 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point.vectProduct(a, b) >= 0
		&& point.vectProduct(b, c) >= 0
		&& point.vectProduct(c, a) >= 0)
		return (true);
	else if (point.vectProduct(a, b) < 0
		&& point.vectProduct(b, c) < 0
		&& point.vectProduct(c, a) < 0)
		return (true);
	else
		return (false);
}
