/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/02 17:32:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init(char *title)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) == NULL ||
		(mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL)
		return (mlxdel(mlx));
	mlx->cam->scale = 16;
	return (mlx);
}
