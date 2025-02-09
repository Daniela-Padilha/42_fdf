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

t_point	cartesian_to_iso(t_point cartesian)
{
	t_point	isometric;

	isometric.x = (cartesian.x - cartesian.y);
	isometric.y = (cartesian.y + cartesian.x) / 2 - cartesian.z;
	isometric.z = cartesian.z;
	return (isometric);
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point0;
	t_point	point1;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			point0.x = x;
            point0.y = y;
            point0.z = get_z_value(fdf, x, y);
			printf("Original: x0: %d, y0: %d, z0: %d\n", point0.x, point0.y, point0.z);
			point0 = cartesian_to_iso(point0);
			printf("After iso: x0: %d, y0: %d, z0: %d\n", point0.x, point0.y, point0.z);
            scale_and_center(fdf, &point0);
			if (x < fdf->width - 1)
            {
				ft_printf("x0: %i, y0: %i, z0: %i\n",point0.x, point0.y, point0.z);
            	point1.x = x + 1;
                point1.y = y;
                point1.z = get_z_value(fdf, x + 1, y);
				printf("Horizontal next: x1: %d, y1: %d, z1: %d\n", point1.x, point1.y, point1.z);
                point1 = cartesian_to_iso(point1);
				printf("After iso: x1: %d, y1: %d, z1: %d\n", point1.x, point1.y, point1.z);
                scale_and_center(fdf, &point1);
                draw_line(fdf, point0, point1, BLUE);
            }
			if (y < fdf->height - 1)
            {
            	point1.x = x;
                point1.y = y + 1;
                point1.z = get_z_value(fdf, x, y + 1);
				printf("Vertical next: x1: %d, y1: %d, z1: %d\n", point1.x, point1.y, point1.z);
                point1 = cartesian_to_iso(point1);
				printf("After iso: x1: %d, y1: %d, z1: %d\n", point1.x, point1.y, point1.z);
                scale_and_center(fdf, &point1);
                draw_line(fdf, point0, point1, BLUE);
            }
			x++;
			printf("\n");
		}
		y++;
	}
}

//info --> draws a line using Bresenham algorithm

void	draw_line(t_fdf *fdf, t_point point0, t_point point1, int color)
{
	fdf->delta = malloc(sizeof(t_delta));
	if (!fdf->delta)
		errors("Error: mem allocation for delta failed", NULL, 1);
	if (point0.x == point1.x && point0.y == point1.y)
	{
		free (fdf->delta);
		return ;
	}
	if (point0.x < 0 || point0.x >= DISP_X || point0.y < 0
		|| point0.y >= DISP_Y || point1.x < 0 || point1.x >= DISP_X
		|| point1.y < 0 || point1.y >= DISP_Y)
    	return ;
	fdf->delta->dx = point1.x - point0.x;
	fdf->delta->dy = point1.y - point0.y;
	if (abs(fdf->delta->dx) >= abs(fdf->delta->dy))
		slope_less1(fdf, &point0, &point1, color);
	else
		slope_bigger1(fdf, &point0, &point1, color);
	free(fdf->delta);
}

void	slope_bigger1(t_fdf *fdf, t_point *point0, t_point *point1, int color)
{
	int	p;

	p = 2 * abs(fdf->delta->dx) - abs(fdf->delta->dy);
	while (point0->y <= point1->y)
	{
		pixel_put(fdf, point0->x, point0->y, color);
		point0->y++;
		if (p < 0)
			p = p + 2 * abs(fdf->delta->dx);
		else
		{
			p = p + 2 * abs(fdf->delta->dx) - 2 * abs(fdf->delta->dy);
			point0->x++;
		}
	}
	return ;
}

void	slope_less1(t_fdf *fdf, t_point *point0, t_point *point1, int color)
{
	int	p;

	p = 2 * abs(fdf->delta->dy) - abs(fdf->delta->dx);
	while (point0->x <= point1->x)
	{
		pixel_put(fdf, point0->x, point0->y, color);
		point0->x++;
		if (p < 0)
			p = p + 2 * abs(fdf->delta->dy);
		else
		{
			p = p + 2 * abs(fdf->delta->dy) - 2 * abs(fdf->delta->dx);
			point0->y++;
		}
	}
	return ;
}

