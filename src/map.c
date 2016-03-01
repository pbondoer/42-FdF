/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:43:36 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/01 07:01:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

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
	v->w = (double)1;
	// TODO: error handling
	// TODO: color handling (default to 0xFFFFFF)
	v->color = (v->x == 0 ? 0xFF0000 : (v->y == 0 ? 0xFFFF00 : 0xFFFFFF));
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
