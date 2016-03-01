/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 06:06:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/01 07:51:07 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
#define PI 3.1415

void		render(t_mlx *mlx, t_map *map)
{
	int			x;
	int			y;
	t_vector	v;
	static t_vector	r;

	int scale = 16;
	r.x = 0;
	r.y = 0;
	r.z = 0;
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			v = *map->vectors[x * map->height + y];
			v.x -= (double)map->width / 2;
			v.y -= (double)map->height / 2;
			v = ortho(rotate(v, r));
			printf("%f, %f, %f, %f\n", v.x, v.y, v.z, v.w);
			mlx_pixel_put(mlx->mlx, mlx->window, (((mlx->width) / 2) + (int)(v.x * scale)), ((mlx->height) / 2 + (int)(v.y * scale)), v.color);
			y++;
		}
		x++;
	}
}
