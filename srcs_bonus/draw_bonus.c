/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:01 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:01 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf_bonus.h"

//info --> draws the whole map

void	draw_map(t_fdf *fdf, t_line *params)
{
	int		y;
	t_point	current;

	if (!fdf || !fdf->map || !params)
	{
		errors("Error: Null pointer detected in draw_map", NULL, 0);
		return ;
	}
	ft_memset(fdf->addr, 0, fdf->win_height * fdf->line_length);
	y = 0;
	while (y < fdf->height)
	{
		current.x = 0;
		current.y = y;
		while (current.x < fdf->width)
		{
			current.z = get_z_value(fdf, current.x, current.y);
			draw_part2(fdf, params, &current);
			current.x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	draw_part2(t_fdf *fdf, t_line *params, t_point *current)
{
	t_point	*next;

	next = malloc(sizeof(t_point));
	if (next == NULL)
	{
		errors("Error: memory allocation of next failed", NULL, 0);
		return ;
	}
	if (current->x < fdf->width - 1)
	{
		next->x = current->x + 1;
		next->y = current->y;
		next->z = get_z_value(fdf, next->x, next->y);
		draw_transformed_line(fdf, params, current, next);
	}
	if (current->y < fdf->height - 1)
	{
		next->x = current->x;
		next->y = current->y + 1;
		next->z = get_z_value(fdf, next->x, next->y);
		draw_transformed_line(fdf, params, current, next);
	}
	free(next);
}

//info --> handles the transformations

void	draw_transformed_line(t_fdf *fdf, t_line *params, t_point *p0,
			t_point *p1)
{
	t_point	transformed_p0;
	t_point	transformed_p1;

	transformed_p0 = cartesian_to_iso(*p0, fdf);
	transformed_p1 = cartesian_to_iso(*p1, fdf);
	scale_and_center(fdf, &transformed_p0);
	scale_and_center(fdf, &transformed_p1);
	draw_line(fdf, &transformed_p0, &transformed_p1, params);
}

//info   --> draws a line using Bresenham algorithm
//dx, dy --> difference between p0 and p1
//p	     --> decision parameter
//steps  --> the movements we will make
//p2     --> determine whether to move diagonally or along a single axis 

void	draw_line(t_fdf *fdf, t_point *p0, t_point *p1, t_line *params)
{
	if (p0->x < 0 || p0->x >= fdf->win_width || p0->y < 0 || p0->y >= fdf->win_height
		|| p1->x < 0 || p1->x >= fdf->win_width || p1->y < 0 || p1->y >= fdf->win_height)
		return ;
	params->dx = abs(p1->x - p0->x);
	params->dy = -abs(p1->y - p0->y);
	if (p0->x < p1->x)
		params->step_x = 1;
	else
		params->step_x = -1;
	if (p0->y < p1->y)
		params->step_y = 1;
	else
		params->step_y = -1;
	params->p = params->dx + params->dy;
	decision_maker(fdf, *p0, *p1, params);
}

void	decision_maker(t_fdf *fdf, t_point p0, t_point p1, t_line *params)
{
	int	p2;

	while (1)
	{
		pixel_put(fdf, p0.x, p0.y, fdf->color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
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
