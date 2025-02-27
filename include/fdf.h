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

# define DISP_Y			1080
# define DISP_X		 	1920

# define KEY_ESC		65307

# define SCALE			25

# define WHITE	0xFFFFFF
# define RED	0x00FF0000
# define BLACK	0x000000
# define BLUE	0x0000FF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	p;
}	t_line;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*map_name;
	int			**map;
	int			height;
	int			width;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
	double		scale;
	t_point		*point;
	t_line		*params;
}	t_fdf;

//Start
void	fdf_init(t_fdf *fdf);
void	params_init(t_line *params);

//Points (parsing)
int		**read_file(t_fdf *fdf, int i);
int		map_height(t_fdf *fdf);
int		map_width(t_fdf *fdf);
int		*line_to_ints(char *line);

//Draw
void	draw_map(t_fdf *fdf, t_line *params);
void	draw_part2(t_fdf *fdf, t_line *params, t_point *current);
void	draw_transformed_line(t_fdf *fdf, t_line *params, t_point *p0,
			t_point *p1);
void	draw_line(t_fdf *fdf, t_point *p0, t_point *p1, t_line *params);
void	decision_maker(t_fdf *fdf, t_point p0, t_point p1, t_line *params);

//Draw_utils
t_point	cartesian_to_iso(t_point cartesian, t_fdf *fdf);
void	center(t_fdf *fdf, t_point *point);
int		get_z_value(t_fdf *fdf, int x, int y);
void	pixel_put(t_fdf *fdf, int x, int y, int color);
t_point	get_next_point(t_fdf *fdf, int x, int y);

//Hooks
int		handle_keys(int keycode, void *params);
int		handle_events(t_fdf *fdf);
int		clean_up(t_fdf *fdf);

//Utils
char	*check_args(int ac, char **av);
int		ft_count_nbr(char *str, int i, int count, int in_nbr);
int		ft_str_isalnum(char *c);

#endif