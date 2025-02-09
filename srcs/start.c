/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:28:11 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/30 23:28:11 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//info --> initializes the struct

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		errors("Error: mlx initialization failed", NULL, 1);
	fdf->win = mlx_new_window(fdf->mlx, DISP_X, DISP_Y, "FdF");
	if (!fdf->win)
		errors("Error: window creation failed", NULL, 1);
	fdf->img = mlx_new_image(fdf->mlx, DISP_X, DISP_Y);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	fdf->scale = 25.0;
	fdf->map = read_file(fdf);
	fdf->height = map_height(fdf);
	fdf->width = map_width(fdf);
	fdf->color = RED;
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
