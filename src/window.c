/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/19 05:12:33 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->image != NULL)
	{
		if (mlx->image->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image->image);
		ft_memdel((void **)&mlx->image);
	}
	ft_memdel((void **)&mlx);
	return (NULL);
}

int			new_image(t_mlx *mlx)
{
	if ((mlx->image = ft_memalloc(sizeof(t_image))) == NULL ||
		(mlx->image->image = mlx_new_image(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT)) == NULL)
		return (1);
	mlx->image->ptr = mlx_get_data_addr(mlx->image->image, &mlx->image->bpp,
			&mlx->image->stride, &mlx->image->endian);
	printf("bpp: %d\nstride: %d\nendian: %d\n", mlx->image->bpp, mlx->image->stride, mlx->image->endian);
	return (0);
}

t_mlx		*init(char *title)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) == NULL ||
		(mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL ||
		(mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL ||
		new_image(mlx))
		return (mlxdel(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offsetX = WIN_WIDTH / 2;
	mlx->cam->offsetY = WIN_HEIGHT / 2;
	return (mlx);
}
