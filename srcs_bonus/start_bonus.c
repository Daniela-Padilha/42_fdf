/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:27:16 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:27:16 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

//info --> initializes the struct

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win_width = INIT_WIDTH;
	fdf->win_height = INIT_HEIGHT;
	if (!fdf->mlx)
		errors("Error: mlx initialization failed", NULL, 1);
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "FdF");
	if (!fdf->win)
		errors("Error: window creation failed", NULL, 1);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	fdf->scale = SCALE;
	fdf->map = read_file(fdf);
	fdf->height = map_height(fdf);
	fdf->width = map_width(fdf);
	fdf->color = BLUE;
	fdf->params = malloc(sizeof(t_line));
	if (!fdf->params)
		errors("Error: memory allocation for params failed", NULL, 1);
}

void	params_init(t_line *params)
{
	params->dx = 0;
	params->dy = 0;
	params->step_x = 0;
	params->step_y = 0;
	params->p = 0;
}
