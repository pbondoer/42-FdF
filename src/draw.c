/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:06:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/02 18:50:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void		line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	int x1 = (int)p1.x;
	int x2 = (int)p2.x;
	int y1 = (int)p1.y;
	int y2 = (int)p2.y;

	int dx = ft_abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = ft_abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, x1, y1, p1.color);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
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
			v = project_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, project_vector(vector_at(map, x + 1, y), mlx), v);
			if (y + 1 < map->height)
				line(mlx, v, project_vector(vector_at(map, x, y + 1), mlx));
			mlx_pixel_put(mlx->mlx, mlx->window, (int)v.x, (int)v.y, v.color);
			y++;
		}
		x++;
	}
}
