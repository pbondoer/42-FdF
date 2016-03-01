/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/01 05:38:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

t_mlx		*cleanup(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	return (NULL);
}

t_mlx		*init(int x, int y, char *title)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((mlx->window = mlx_new_window(mlx->mlx, x, y, title)) == NULL)
		return (cleanup(mlx));
	mlx->width = x;
	mlx->height = x;
	return (mlx);
}
