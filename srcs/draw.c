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
	t_point isometric;

    isometric.x = cartesian.x - cartesian.y;
    isometric.y = (cartesian.x + cartesian.y) / 2 - cartesian.z;
    isometric.z = cartesian.z;
    return isometric;
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	point0;
	t_point	point1;

	ft_memset(fdf->addr, 0, DISP_Y * fdf->line_length);
	printf("DISP_X: %i, DISP_Y: %i, fdf->width: %i, fdf->height: %i", DISP_X, DISP_Y, fdf->width, fdf->height);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			point0.x = x;
            point0.y = y;
            point0.z = get_z_value(fdf, x, y);
			printf("\nOriginal: x0: %d, y0: %d, z0: %d\n", point0.x, point0.y, point0.z);
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
				printf("Drawing line from (%d, %d) to (%d, %d)\n", point0.x, point0.y, point1.x, point1.y);
                draw_line(fdf, point0, point1, RED);
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
				printf("Drawing line from (%d, %d) to (%d, %d)\n", point0.x, point0.y, point1.x, point1.y);
                draw_line(fdf, point0, point1, RED);
            }
			x++;
			printf("\n");
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	printf("Image put to window\n");
}

//info --> draws a line using Bresenham algorithm

void draw_line(t_fdf *fdf, t_point p0, t_point p1, int color)
{
    int dx;
    int dy;
    int err;
    int e2;
	int sx;
	int	sy;

	printf("Drawing line from (%d, %d) to (%d, %d)\n", p0.x, p0.y, p1.x, p1.y);
	if (p0.x < 0 || p0.x >= DISP_X || p0.y < 0 || p0.y >= DISP_Y ||
        p1.x < 0 || p1.x >= DISP_X || p1.y < 0 || p1.y >= DISP_Y)
        return;
	dx = abs(p1.x - p0.x);
	dy = -abs(p1.y - p0.y);
	err = dx + dy;
	if (p0.x < p1.x)
   	 sx = 1;
	else
   	 sx = -1;

	if (p0.y < p1.y)
   	 sy = 1;
	else
    	sy = -1;
    while (1)
    {
        if (p0.x >= 0 && p0.x < DISP_X && p0.y >= 0 && p0.y < DISP_Y)
            pixel_put(fdf, p0.x, p0.y, color);
        if (p0.x == p1.x && p0.y == p1.y)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            p0.x += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            p0.y += sy;
        }
    }
}


