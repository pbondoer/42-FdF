/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:26:39 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/20 14:54:24 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

double		**new_zbuffer()
{
	double	**zbuf;
	int		i;

	if ((zbuf = ft_memalloc(WIN_WIDTH * sizeof(double *))) == NULL)
		return (NULL);
	i = 0;
	while (i < WIN_WIDTH)
		if ((zbuf[i++] = ft_memalloc(WIN_HEIGHT * sizeof(double))) == NULL)
			return (del_zbuffer(zbuf));
	return (zbuf);
}

double		**del_zbuffer(double **zbuf)
{
	int i;

	if (zbuf != NULL)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			if (zbuf[i] != NULL)
				ft_memdel((void **)&zbuf[i]);
			i++;
		}
		ft_memdel((void **)&zbuf);
	}
	return (NULL);
}
