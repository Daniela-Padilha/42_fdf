/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:31:46 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/31 16:31:46 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void apply_scale_factor(t_fdf *fdf)
{
    float scale_factor_x = (float)DISP_X / fdf->width;
    float scale_factor_y = (float)DISP_Y / fdf->height;

    // Optional: To keep the aspect ratio of the map
    fdf->scale = fmin(scale_factor_x, scale_factor_y);
}

void	draw_map(t_fdf *fdf, int color)
{
	int	x;
	int	y;
	
	apply_scale_factor(fdf);
	fdf->delta = malloc(sizeof(t_delta));
	if (!fdf->delta)
		errors("Error: mem allocation for delta failed");
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
		if (x < fdf->width - 1)
    		draw_line(fdf,
              (t_point){(x - fdf->width / 2) * fdf->scale, (y - fdf->height / 2) * fdf->scale},
              (t_point){(x - fdf->width / 2 + 1) * fdf->scale, (y - fdf->height / 2) * fdf->scale},
              color);

		if (y < fdf->height - 1)
   			draw_line(fdf,
              (t_point){(x - fdf->width / 2) * fdf->scale, (y - fdf->height / 2) * fdf->scale},
              (t_point){(x - fdf->width / 2) * fdf->scale, (y - fdf->height / 2 + 1) * fdf->scale},
              color);

			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

//info --> draws a line using Bresenham algorithm

void	draw_line(t_fdf *fdf, t_point point0, t_point point1, int color)
{
	if (!fdf->delta)
		errors("Error: mem allocation for delta failed");
	fdf->delta->dx = point1.x - point0.x;
	fdf->delta->dy = point1.y - point0.y;
	if (abs(fdf->delta->dx) >= abs(fdf->delta->dy))
		slope_less1(fdf, point0, point1, color);
	else
		slope_bigger1(fdf, point0, point1, color);
}

void	slope_bigger1(t_fdf *fdf, t_point point0, t_point point1, int color)
{
	int	p;

	p = 2 * abs(fdf->delta->dx) - abs(fdf->delta->dy);
	while (point0.y <= point1.y)
	{
		if (point0.x >= 0 && point0.x < fdf->width && point0.y >= 0 && point0.y < fdf->height)
			pixel_put(fdf, point0.x, point0.y, color);
		ft_printf("Plotting pixel at (%d, %d)\n", point0.x, point0.y);
		if (fdf->delta->dy > 0)
			point0.y++;
		else
			point0.y--;
		if (p < 0)
			p = p + 2 * abs(fdf->delta->dx);
		else
		{
			if (fdf->delta->dx > 0)
				point0.x++;
			else
				point0.x--;
			p = p + 2 * abs(fdf->delta->dx) - 2 * abs(fdf->delta->dy);
		}
	}
}

void	slope_less1(t_fdf *fdf, t_point point0, t_point point1, int color)
{
	int	p;

	p = 2 * abs(fdf->delta->dy) - abs(fdf->delta->dx);
	while (point0.x <= point1.x)
	{
		if (point0.x >= 0 && point0.x < fdf->width && point0.y >= 0 && point0.y < fdf->height)
			pixel_put(fdf, point0.x, point0.y, color);
		ft_printf("Plotting pixel at (%d, %d)\n", point0.x, point0.y);
		if (fdf->delta->dx > 0)
			point0.x++;
		else
			point0.x--;
		if (p < 0)
			p = p + 2 * abs(fdf->delta->dy);
		else
		{
			if (fdf->delta->dy > 0)
				point0.y++;
			else
				point0.y--;
			p = p + 2 * abs(fdf->delta->dy) - 2 * abs(fdf->delta->dx);
		}
	}
}

void  isometric(t_vector *vector)
{
 int tmp;

 tmp = vector->x;
 vector->x = (tmp - vector->y) * cos(0.523599);
 vector->y = (tmp + vector->y) * sin(0.523599) - vector->z;
}
