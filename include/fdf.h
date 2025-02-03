/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:03:28 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/28 16:03:28 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

# define DISP_Y	1000
# define DISP_X	1900

# define KEY_ESC	65307
# define KEY_SUM	65451
# define KEY_MINUS	65453
# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define MOUSE_MIDDLE	3
# define MOUSE_UP		4
# define MOUSE_DOWN		5

# define ZOOM_FACTOR	1

# define WHITE	0xFFFFFF
# define RED	0x00FF0000
# define BLACK	0x000000
# define BLUE	0x0000FF

typedef struct s_vector 
{
	int		x;
	int		y;
	int		z;
}	t_vector;

typedef struct s_point 
{
	int	x;
	int	y;
}	t_point;

typedef struct s_delta 
{
	int	dx;
	int	dy;
}	t_delta;

typedef struct s_fdf 
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*map_name;
	int			**map;
	int			height;
	int			width;
	int			z;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			scale;
	int			slope;
	int			center_x;
	int			center_y;
	int			in_x;
	int			in_y;
	t_vector	*vector;
	t_point		*point;
	t_delta		*delta;
}	t_fdf;

//Start
void	fdf_init(t_fdf *fdf);
int		render(t_fdf *fdf);

//Points
int		**read_file(t_fdf *fdf);
int		map_height(t_fdf *fdf);
int		map_width(t_fdf *fdf);
int 	*line_to_ints(char *line);
void	center_and_scale(t_fdf *fdf);

//Events
int 	close_window(t_fdf *fdf);
int		handle_keys(t_fdf *fdf, int keycode);
int		handle_events(t_fdf *fdf);
int		handle_mouse(t_fdf *fdf, int mousecode);

//Draw
void	draw_map(t_fdf *fdf, int color);
void	draw_line(t_fdf *fdf, t_point point0, t_point point1, int color);
void	slope_bigger1(t_fdf *fdf, t_point point0, t_point point1, int color);
void	slope_less1(t_fdf *fdf, t_point point0, t_point point1, int color);

//Utils
char	*check_args(int ac, char **av);
int		ft_count_nbr(char *str);
int		get_z_value(t_fdf *fdf);
void	pixel_put(t_fdf *fdf, int x, int y, int color);

#endif