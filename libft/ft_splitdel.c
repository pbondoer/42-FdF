/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:58:56 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/26 04:20:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitdel(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*split)[i];
	}
	ft_memdel((void **)split);
	return (0);
}
