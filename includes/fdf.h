/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:59:07 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/02 18:37:27 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT	420
# define WIN_WIDTH	420

typedef struct		s_cam
{
	double		x;
	double		y;
	double		z;
	int			scale;
}					t_cam;
typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}					t_vector;
typedef struct		s_map
{
	int			width;
	int			height;
	t_vector	**vectors;
}					t_map;
typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_cam		*cam;
}					t_mlx;
int					read_file(int fd, t_map **map);
t_vector			*get_vector(int x, int y, char *str);
t_map				*get_map(int width, int height);
t_mlx				*init(char *title);
void				render(t_mlx *mlx);
t_vector			rotate(t_vector p, t_cam *r);
t_vector			vector_at(t_map *map, int x, int y);
t_vector			project_vector(t_vector p, t_mlx *mlx);
#endif
