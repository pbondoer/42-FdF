/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:59:07 by pbondoer          #+#    #+#             */
/*   Updated: 2016/05/20 14:53:51 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720

typedef struct		s_cam
{
	double		offsetX;
	double		offsetY;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
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
typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;
typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;
typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
}					t_mlx;
int					read_file(int fd, t_map **map);
t_vector			*get_vector(int x, int y, char *str);
t_map				*get_map(int width, int height);
t_mlx				*init(char *title);
void				render(t_mlx *mlx);
t_vector			rotate(t_vector p, t_cam *r);
t_vector			vector_at(t_map *map, int x, int y);
t_vector			project_vector(t_vector p, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
void				set_pixel(t_image *image, int x, int y, int color);
void				clear_image(t_image *image);
int					lineclip(t_vector *p1, t_vector *p2);
t_image				*new_image(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
double				**new_zbuffer();
double				**del_zbuffer(double **zbuf);
#endif
