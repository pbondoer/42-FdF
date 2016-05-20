/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:06:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/20 12:23:30 by pbondoer         ###   ########.fr       */
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

	if (c1 == c2)
		return (c1);

	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);

	return (r << 16 | g << 8 | b);
}

void		line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;

	double startx = p1.x;
	double starty = p1.y;

	if (!lineclip(&p1, &p2))
		return ;

	int dx = ft_abs((int)p2.x - (int)p1.x);
	int sx = (int)p1.x < (int)p2.x ? 1 : -1;
	int dy = ft_abs((int)p2.y - (int)p1.y);
	int sy = (int)p1.y < (int)p2.y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	double percent = 0.0f;

	while ((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y)
	{
		//printf("draw: %f %f -> %f %f\n", p1.x, p1.y, p2.x, p2.y);
		//if ((p1.x < 0 || p1.x >= WIN_WIDTH || p1.y < 0 || p1.y >= WIN_HEIGHT)
		//	&& (p2.x < 0 || p2.x >= WIN_WIDTH || p2.y < 0 || p2.y >= WIN_HEIGHT))
		//	break ;
		percent = (dx > dy ? ft_ilerp((int)p1.x, (int)startx, (int)p2.x) : ft_ilerp((int)p1.y, (int)starty, (int)p2.y));
		//printf("%f; %f - %f; %f === %f\n", p1.x, p1.y, p2.x, p2.y, percent);
		//mlx_pixel_put(mlx->mlx, mlx->window, (int)p1.x, (int)p1.y, clerp(p1.color, p2.color, percent));
		set_pixel(mlx->image, (int)p1.x, (int)p1.y, clerp(p1.color, p2.color, percent));
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
	//mlx_clear_window(mlx->mlx, mlx->window);
	clear_image(mlx->image);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			//printf("%d %d\n", x, y);
			v = project_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, v, project_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				line(mlx, v, project_vector(vector_at(map, x, y + 1), mlx));
			//mlx_pixel_put(mlx->mlx, mlx->window, (int)v.x, (int)v.y, v.color);
			y++;
		}
		x++;
	}
	//set_pixel(mlx, 0, 0, 0xFFAABB);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
