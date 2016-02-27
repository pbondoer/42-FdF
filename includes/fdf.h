/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:59:07 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/26 08:13:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_cam
{
	int			r;
	int			l;
	int			t;
	int			b;
	int			f;
	int			n;
}					t_cam;
typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
}					t_mlx;
typedef struct		s_vector
{
	int			x;
	int			y;
	int			z;
	int			w;
	int			color;
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
t_vector			ortho(t_vector p, t_cam c);
#endif
