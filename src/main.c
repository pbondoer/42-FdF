/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:42:21 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/11 00:37:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

//int		key_down(int code, t_mlx *mlx)
//{
//
//}

int		die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
		return die("error: not enough arguments");
	fd = open(argv[1], O_RDONLY);
	printf("opened %s with fd %d\n", argv[1], fd);
	if (fd < 0 || !read_file(fd, &map))
		return die("error: invalid file");
	if ((mlx = init(ft_strjoin("FdF - ", argv[1]))) == NULL)
		return die("error: mlx couldn't init");
	mlx->map = map;
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offsetX = WIN_WIDTH / 2;
	mlx->cam->offsetY = WIN_HEIGHT / 2;
	render(mlx);
//	mlx_hook(mlx->window, 2, 3, key_down, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

