/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:57:26 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/13 18:50:11 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//info --> transform from cartesian to isometric

t_point	cartesian_to_iso(t_point cartesian, t_fdf *fdf)
{
	t_point isometric;

    cartesian.x *= fdf->scale;
    cartesian.y *= fdf->scale;
    cartesian.z *= fdf->scale;
    isometric.x = cartesian.x - cartesian.y;
    isometric.y = (cartesian.x + cartesian.y) / 2 - cartesian.z;
    isometric.z = cartesian.z;
    return isometric;
}

//info --> aplly scale and center the map

void	scale_and_center(t_fdf *fdf, t_point *point)
{
    int offset_x;
    int offset_y;

    (void)fdf;
	offset_x = 500;
	offset_y = 500;
    point->x = (int)point->x + offset_x;
    point->y = (int)point->y + offset_y;
    point->z = point->z;
    point->x = fmax(0, fmin(point->x, DISP_X - 1));
    point->y = fmax(0, fmin(point->y, DISP_Y - 1));
}

//info --> returns the int at position row y, collumn x

int	get_z_value(t_fdf *fdf, int x, int y)
{
	if (x < 0 || y < 0 || y >= fdf->height || x >= fdf->width)
		errors("Error: Out of bounds", NULL, 0);
	return (fdf->map[y][x]);
}

//info --> draws a pixel and colors it

void	pixel_put(t_fdf *fdf, int x, int y, int color)
{
    char *pxl;

    if (x < 0 || y < 0 || x >= DISP_X || y >= DISP_Y)
        return;
    pxl = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
    *(unsigned int *)pxl = color;
}

//info --> retrieves and initializes the next point

t_point get_next_point(t_fdf *fdf, int x, int y)
{
    t_point next;

    next.x = x;
    next.y = y;
    next.z = get_z_value(fdf, x, y);
    return next;
}
