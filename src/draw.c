/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:06:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/12 00:25:30 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdio.h>

int			clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);

	return (r << 16 | g << 8 | b);
}

void		line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	int dx = ft_abs((int)p2.x - (int)p1.x);
	int sx = (int)p1.x < (int)p2.x ? 1 : -1;
	int dy = ft_abs((int)p2.y - (int)p1.y);
	int sy = (int)p1.y < (int)p2.y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	double startx = p1.x;
	double starty = p1.y;
	double percent = 0.0f;

	// temporary fix
	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	
	while ((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y)
	{
		percent = (dx > dy ? ft_ilerp((int)p1.x, (int)startx, (int)p2.x) : ft_ilerp((int)p1.y, (int)starty, (int)p2.y));
		//printf("%f; %f - %f; %f === %f\n", p1.x, p1.y, p2.x, p2.y, percent);
		mlx_pixel_put(mlx->mlx, mlx->window, (int)p1.x, (int)p1.y, clerp(p1.color, p2.color, percent));
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p1.y += sy;
		}
	}
}

void		render(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	mlx_clear_window(mlx->mlx, mlx->window);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			printf("%d, %d\n", x, y);
			v = project_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, v, project_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				line(mlx, v, project_vector(vector_at(map, x, y + 1), mlx));
			mlx_pixel_put(mlx->mlx, mlx->window, (int)v.x, (int)v.y, v.color);
			y++;
		}
		x++;
	}
}
