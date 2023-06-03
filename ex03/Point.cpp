/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:39:26 by eberger           #+#    #+#             */
/*   Updated: 2023/06/03 11:40:12 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed())
{
	return ;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point::Point(const Point &obj) : _x(obj.getX()), _y(obj.getY())
{
	return ;
}

Point&	Point::operator=(Point &obj)
{
	return (obj);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::diffY(const Point &obj) const
{
	return (this->getY() - obj.getY());
}

Fixed	Point::diffX(const Point &obj) const
{
	return (this->getX() - obj.getX());
}

Fixed	Point::vectProduct(const Point &frst, const Point &secnd) const
{
	return (frst.diffX(*this) * secnd.diffY(*this) - frst.diffY(*this) * secnd.diffX(*this));
}
