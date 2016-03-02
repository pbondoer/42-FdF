/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 08:04:43 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/02 14:41:28 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

t_vector	rotate(t_vector p, t_vector r)
{
	t_vector v;
	double x;
	double y;
	double z;

	v.w = 1;

	x = p.x;
	z = p.z;
	//y
	v.x = cos(r.y) * x + sin(r.y) * z;
	v.y = p.y;
	v.z = -sin(r.y) * x + cos(r.y) * z;

	y = v.y;
	z = v.z;
	//x
	v.y = cos(r.x) * y - sin(r.x) * z;
	v.z = - sin(r.x) * y + cos(r.x) * z;
	
	x = v.x;
	y = v.y;
	//z
	v.x = cos(r.z) * x - sin(r.z) * y;
	v.y = sin(r.z) * x + cos(r.z) * y;
	//printf("%f, %f, %f\n", v.x, v.y, v.z);
	v.color = p.color;
	return (v);
}

t_vector	ortho(t_vector p)
{
	return (p);
	t_vector v;

	v.w = p.w;
	v.z = 0;

	double omega = 0.7853f;
	double alpha = 0.6154f;

	double A1 = cos(omega);
	double A2 = sin(omega);
	double B1 = cos(alpha);
	double B2 = sin(alpha);

	v.x = A1 * p.x + A2 * p.y;
	v.y = B2 * (A2 * p.x - A1 * p.y) + B1 * p.z;
	v.color = p.color;
	return (v);
}
