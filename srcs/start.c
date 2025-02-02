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
	fdf->win = mlx_new_window(fdf->mlx, DISP_X, DISP_Y, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, DISP_X, DISP_Y);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, &fdf->line_length,
									&fdf->endian);
	fdf->map = read_file(fdf);
	fdf->height = map_height(fdf);
	fdf->width = map_width(fdf);
	fdf->z = get_z_value(fdf);
}
