/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:43:36 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/11 23:14:07 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_vector	project_vector(t_vector v, t_mlx *mlx)
{
	v.x -= (double)mlx->map->width / 2.0;
	v.y -= (double)mlx->map->height / 2.0;
	v.z -= 5; // TODO: z offset
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetX;
	v.y += mlx->cam->offsetY;
	return (v);
}

t_vector	vector_at(t_map *map, int x, int y)
{
	return (*map->vectors[y * map->width + x]);
}

t_vector	*get_vector(int x, int y, char *str)
{
	t_vector	*v;
	//char		**split;
	
	v = ft_memalloc(sizeof(t_vector));
	if (v == NULL)
		return (NULL);
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	// TODO: error handling
	// TODO: color handling (default to 0xFFFFFF)
	v->color = ((int)v->x % 2 == 0 ? 0xFF0000 : ((int)v->y % 2 == 0 ? 0x00FF00 : 0x0000FF));
	return (v);
}

t_map		*get_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->vectors = ft_memalloc(sizeof(t_vector *) * width * height);
	if (map->vectors == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}
