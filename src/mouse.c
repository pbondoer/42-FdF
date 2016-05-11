/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 22:39:22 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/12 01:22:10 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse down, button %d: %d %d\n", button, x, y);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse up, button %d: %d %d\n", button, x, y);
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	//printf("motion notify: %d %d\n", x, y);

	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;

	if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->cam->x += (mlx->mouse->lasty - y) / 200.0f;
		mlx->cam->y -= (mlx->mouse->lastx - x) / 200.0f;
		render(mlx);
	}
	//TODO: only render if changed
	return (0);
}
