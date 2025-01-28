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
}			t_fdf;

int	close_window(t_fdf *fdf);
int	handle_keys(int keycode, t_fdf *fdf);

#endif