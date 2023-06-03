/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:26:16 by eberger           #+#    #+#             */
/*   Updated: 2023/06/03 11:39:47 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {

public:

	Point(void);
	Point(const float x, const float y);
	~Point(void);
	Point(const Point &obj);
	Point& operator=(Point &obj);
	Fixed	getY(void) const;
	Fixed	getX(void) const;
	Fixed	diffY(const Point &obj) const;
	Fixed	diffX(const Point &obj) const;
	Fixed	vectProduct(const Point &frst, const Point &secnd) const;

private:

	const Fixed	_x;
	const Fixed	_y;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
