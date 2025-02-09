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

//info --> draws the whole map

void	draw_map(t_fdf *fdf, t_line *params)
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
			point0 = cartesian_to_iso(point0);
            scale_and_center(fdf, &point0);
			if (x < fdf->width - 1)
            {
				ft_printf("x0: %i, y0: %i, z0: %i\n",point0.x, point0.y, point0.z);
            	point1.x = x + 1;
                point1.y = y;
                point1.z = get_z_value(fdf, x + 1, y);
                point1 = cartesian_to_iso(point1);
                scale_and_center(fdf, &point1);
                draw_line(fdf, point0, point1, params);
            }
			if (y < fdf->height - 1)
            {
            	point1.x = x;
                point1.y = y + 1;
                point1.z = get_z_value(fdf, x, y + 1);
                point1 = cartesian_to_iso(point1);
                scale_and_center(fdf, &point1);
                draw_line(fdf, point0, point1, params);
            }
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

//info   --> draws a line using Bresenham algorithm
//dx, dy --> difference between p0 and p1
//p      --> decision parameter
//steps  --> the movements we will make
//p2     --> determine whether to move diagonally or along a single axis 

void	draw_line(t_fdf *fdf, t_point p0, t_point p1, t_line *params)
{
	if (p0.x < 0 || p0.x >= DISP_X || p0.y < 0 || p0.y >= DISP_Y ||
        p1.x < 0 || p1.x >= DISP_X || p1.y < 0 || p1.y >= DISP_Y)
        return ;
	params->dx = abs(p1.x - p0.x);
	params->dy = -abs(p1.y - p0.y);
	if (p0.x < p1.x)
   		params->step_x = 1;
	else
   		params->step_x = -1;
	if (p0.y < p1.y)
   		params->step_y = 1;
	else
    	params->step_y = -1;
	params->p = params->dx + params->dy;
	decision_maker(fdf, p0, p1, params);
}

void	decision_maker(t_fdf *fdf, t_point p0, t_point p1, t_line *params)
{
    int p2;

    while (1)
    {
		pixel_put(fdf, p0.x, p0.y, fdf->color);
        if (p0.x == p1.x && p0.y == p1.y)
            break;
        p2 = 2 * params->p;
        if (p2 >= params->dy)
        {
            params->p += params->dy;
            p0.x += params->step_x;
        }
        if (p2 <= params->dx)
        {
            params->p += params->dx;
            p0.y += params->step_y;
        }
    }
}
