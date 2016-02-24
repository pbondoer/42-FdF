/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:55:46 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/24 12:35:51 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"
#include <stdio.h>

int		get_lines(int fd, t_list **lst)
{
	t_list	*temp;
	int		expected;
	char	*line;
	int		ret;

	expected = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (expected == -1)
			expected = (int)ft_countwords(line, ' ');
		else if (expected != (int)ft_countwords(line, ' '))
		{
			ret = -1;
			break ;
		}
		temp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_strdel(&line);
		if (temp == NULL)
		{
			ret = -1;
			break ;
		}
		ft_lstadd(lst, temp);
	}
	if (expected == -1) // read nothing
		return (0);
	if (ret == -1)
	{
		//ft_lstdel(lst, strdel);
		//TODO: delete our list if it fails part-way
		return (0);
	}
	ft_lstrev(lst);
	return (1);
}

int		read_file(int fd, t_map **m)
{
	t_list		*lines;
	int			x;
	int			y;
	char		**split;
	t_map		*map;
	t_vector	*v;
	lines = NULL;
	if (!(get_lines(fd, &lines)))
		return (0);
	map = ft_memalloc(sizeof(t_map));
	map->width = ft_countwords(lines->content, ' ');
	map->height = ft_lstcount(lines);
	map->vectors = ft_memalloc(sizeof(t_vector) * map->width * map->height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		split = ft_strsplit(lines->content, ' ');
		while (x < map->width)
		{
			v = &map->vectors[y * map->width + x];
			v->x = x;
			v->y = y;
			// TODO: error handling
			v->z = ft_atoi(split[x]);
			// TODO: colors
			v->w = 1;
			v->color = 0xFFFFFF;
			x++;
		}
		//TODO: free split
		lines = lines->next;
		y++;
	}
	*m = map;
	return (1);
}
