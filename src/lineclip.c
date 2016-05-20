/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineclip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 07:45:40 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/20 11:55:29 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		region(int x, int y)
{
	int c;

	c = 0;
	if (y >= WIN_HEIGHT)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= WIN_WIDTH)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

int		lineclip(t_vector *p1, t_vector *p2)
{
	int r1;
	int r2;
	int x;
	int y;
	int rout;

	r1 = region(p1->x, p1->y);
	r2 = region(p2->x, p2->y);
	while (!(!(r1 | r2) || (r1 & r2))) // while ( ! (accept || reject) )
	{
		rout = r1 ? r1 : r2;
		//printf("accept: %d | reject: %d | p1: %d %d | p2: %d %d | rout: %d\n", !(r1 | r2), (r1 & r2), (int)p1->x, (int)p1->y, (int)p2->x, (int)p2->y, rout);
		if (rout & 1)
		{
			x = p1->x + (p2->x - p1->x) * (WIN_HEIGHT - p1->y) / (p2->y - p1->y);
			y = WIN_HEIGHT - 1;
		}
		else if (rout & 2)
		{
			x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
			y = 0;
		}
		else if (rout & 4)
		{
			x = WIN_WIDTH - 1;
			y = p1->y + (p2->y - p1->y) * (WIN_WIDTH - p1->x) / (p2->x - p1->x);
		}
		else
		{
			x = 0;
			y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
		}
		if (rout == r1)
		{
			//printf("Point 1 clipped\n");
			p1->x = x;
			p1->y = y;
			r1 = region(p1->x, p1->y);
		}
		else
		{
			//printf("Point 2 clipped\n");
			p2->x = x;
			p2->y = y;
			r2 = region(p2->x, p2->y);
		}
	}
	//printf("Done | p1: %f %f | p2: %f %f\n", p1->x, p1->y, p2->x, p2->y);
	return (!(r1 | r2));
}
