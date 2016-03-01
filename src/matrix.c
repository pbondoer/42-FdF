/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 08:04:43 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/01 07:44:12 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

t_vector	rotate(t_vector p, t_vector r)
{
	t_vector v;

	v.w = 1;
	//x
	v.x = p.x;
	v.y = cos(r.x) * p.y - sin(r.x) * p.y;
	v.z = sin(r.x) * p.z + cos(r.x) * p.z;
	//y
	v.x = cos(r.y) * v.x + sin(r.y) * v.x;
	v.y = v.y;
	v.z = - sin(r.y) * v.z + cos(r.y) * v.z;
	//z
	v.x = cos(r.z) * v.x - sin(r.z) * v.x;
	v.y = sin(r.z) * v.y + cos(r.z) * v.y;
	v.z = v.z;
	printf("%f, %f, %f\n", v.x, v.y, v.z);
	v.color = p.color;
	return (v);
}

t_vector	ortho(t_vector p)
{
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
	v.y = -(B2 * (A2 * p.x - A1 * p.y) + B1 * p.z);
	v.color = p.color;
	return (v);
}
