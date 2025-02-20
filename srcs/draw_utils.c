/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:57:26 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 15:10:09 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//info --> transform from cartesian to isometric

t_point	cartesian_to_iso(t_point cartesian, t_fdf *fdf)
{
	t_point	isometric;

	cartesian.x *= fdf->scale;
	cartesian.y *= fdf->scale;
	cartesian.z *= fdf->scale;
	isometric.x = cartesian.x - cartesian.y;
	isometric.y = (cartesian.x + cartesian.y) / 2 - cartesian.z;
	isometric.z = cartesian.z;
	return (isometric);
}

//info --> aplly scale and center the map

void	center(t_fdf *fdf, t_point *point)
{
	(void)fdf;
	point->x += DISP_X / 2.0;
	point->y += DISP_Y / 2.0;
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
	char	*pxl;

	if (x < 0 || y < 0 || x >= DISP_X || y >= DISP_Y)
		return ;
	pxl = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)pxl = color;
}

//info --> retrieves and initializes the next point

t_point	get_next_point(t_fdf *fdf, int x, int y)
{
	t_point	next;

	next.x = x;
	next.y = y;
	next.z = get_z_value(fdf, x, y);
	return (next);
}
