/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 00:20:47 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/23 00:35:23 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	strdel(void *str, size_t size)
{
	ft_strdel(&str);
	(void)size;
}

int		ft_getlines(int fd, t_list **lst)
{
	t_list	*ptr;
	char	*line;
	int		ret;

	while (ret = get_next_line(fd, &line))
	{
		ptr = ft_lstnew(line, ft_strlen(line));
		ft_strdel(&line);
		if (ptr == NULL)
		{
			ret = -1;
			break ;
		}
		ft_lstadd(&lst, ptr);
	}
	if (ret == -1)
	{
		ft_lstdel(lst, strdel);
		return (0);
	}
	ft_lstrev(lst);
	return (1);
}
