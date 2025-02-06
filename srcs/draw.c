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

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point0;
	t_point	point1;

	y = 0;
	while (y < (fdf->height - 1))
	{
		x = 0;
		while (x < (fdf->width - 1))
		{
			point0.x = x;
			point0.y = y;
			point1.x = x + 1;
			point1.y = y;
			center_and_scale(fdf, &point0, &point1);
			draw_line(fdf, &point0, &point1, BLUE);
			point1.x = x;
			point1.y = y + 1;
			center_and_scale(fdf, &point0, &point1);
			draw_line(fdf, &point0, &point1, BLUE);
			x++;
		}
		y++;
	}
}

//info --> draws a line using Bresenham algorithm

void	draw_line(t_fdf *fdf, t_point *point0, t_point *point1, int color)
{
	fdf->delta = malloc(sizeof(t_delta));
	if (!fdf->delta)
		errors("Error: mem allocation for delta failed", NULL, 1);
	if (point0->x == point1->x && point0->y == point1->y)
	{
		free (fdf->delta);
		return ;
	}
	if (point0->x < 0 || point0->x >= DISP_X || point0->y < 0
		|| point0->y >= DISP_Y || point1->x < 0 || point1->x >= DISP_X
		|| point1->y < 0 || point1->y >= DISP_Y)
	{
		ft_printf("Error: out-of-bounds pixel:(%d,%d)\n", point0->x, point0->y);
		return ;
	}
	fdf->delta->dx = point1->x - point0->x;
	fdf->delta->dy = point1->y - point0->y;
	if (abs(fdf->delta->dx) >= abs(fdf->delta->dy))
		slope_less1(fdf, point0, point1, color);
	else
		slope_bigger1(fdf, point0, point1, color);
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
// void isometric(int x, int y, int *iso_x, int *iso_y)
// {
//     int size = 1;
//     int iso_x = (x - y) * scale + center_x;
// 	int iso_y = (x + y) * scale / 2 + center_y;	
// }
	// int size;
	// t_point vector = {0, 0};
	// (void)x;
	// (void)y;
	// size = 1 / 2;
	// vector.x  = (size * sqrt(3)) + (size * - 1) + (size * (-1 / sqrt(2)));
	// vector.y = (size * -sqrt(3)) + (size * - 1) + (size * (-1 / sqrt(2)));
	// // z = (size * 0.2) + (size * (-1 / sqrt(2)));
	// // vector->x = x;
	// // vector->y = y;
	// // vector->z = z;
	// return(vector);
