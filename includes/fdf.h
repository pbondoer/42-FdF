/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:59:07 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/01 05:56:36 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
}					t_mlx;
typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
	double		w;
	double		color;
}					t_vector;
typedef struct		s_map
{
	int			width;
	int			height;
	t_vector	**vectors;
}					t_map;
int					read_file(int fd, t_map **map);
t_vector			*get_vector(int x, int y, char *str);
t_map				*get_map(int width, int height);
t_mlx				*init(int x, int y, char *title);
void				render(t_mlx *mlx, t_map *map);
t_vector			rotate(t_vector p, t_vector r);
t_vector			ortho(t_vector p);
#endif
