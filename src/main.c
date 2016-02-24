/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:42:21 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/24 12:25:42 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc < 2)
	{
		ft_putstr("error: not enough arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	printf("fd: %d\n", fd);
	if (fd < 0 || !read_file(fd, &map))
	{
		ft_putstr("error: invalid file");
		return (1);
	}
	ft_putstr("read\n");
	int x = 0;
	int y = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			t_vector	*v;
			v = &map->vectors[y * map->width + x];
			y++;
		}
		x++;
	}
	return (0);
}
