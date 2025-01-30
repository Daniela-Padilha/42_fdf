/* ************************************************************************** */
/*                                                                            */
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

# define KEY_ESC	65307
# define KEY_SUM    65451
# define KEY_MINUS  65453
# define MOUSE_LEFT		1
# define MOUSE_RIGHT	2
# define MOUSE_MIDDLE	3
# define MOUSE_UP		4
# define MOUSE_DOWN		5

typedef struct s_fdf {
	void	*mlx;
	void	*win;
  char  *map;
  int   map_height;
  int   map_width;
  char  **matrix_char;
  int   **matrix;
}			t_fdf;

typedef struct s_movement {
  bool up;
  bool down;
  bool left;
  bool right;
} t_movement;



//Base
void	fdf_init(t_fdf *fdf);
char *check_args(int ac, char **av);

//Map
char	**read_file(t_fdf *fdf);


//Events
int	close_window(t_fdf *fdf);
int	handle_keys(int keycode, t_fdf *fdf);

#endif