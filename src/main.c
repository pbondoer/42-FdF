/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:42:21 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/26 08:00:05 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
	{
		printf("error: not enough arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	printf("opened %s with fd %d\n", argv[1], fd);
	if (fd < 0 || !read_file(fd, &map))
	{
		printf("error: invalid file\n");
		return (1);
	}
	if ((mlx = init(512, 512, ft_strjoin("FdF - ", argv[1]))) == NULL)
	{
		printf("error: mlx couldn't init\n");
		return (1);
	}
	render(mlx, map);
	mlx_loop(mlx->mlx);
	return (0);
}
