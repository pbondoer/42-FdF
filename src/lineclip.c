/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineclip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 07:45:40 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/19 07:47:42 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		region(int x, int y)
{
	int c;

	c = 0;
	if (y >= WIN_HEIGHT)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= WIN_WIDTH)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}
