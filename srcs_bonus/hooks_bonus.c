/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:23 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:23 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

//info --> uses the handle functions with hooks

int	handle_events(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, handle_keys, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, handle_mouse, fdf);
	mlx_hook(fdf->win, 17, 0L, clean_up, fdf);
	return (0);
}

//info --> handles mouse events

int	handle_mouse(int mousecode, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (mousecode == SCROLL_UP)
	{
		fdf->scale *= ZOOM_FACTOR;
		if (fdf->scale > MAX_SCALE)
			fdf->scale = MAX_SCALE;
	}
	else if (mousecode == SCROLL_DOWN)
	{
		fdf->scale /= ZOOM_FACTOR;
		if (fdf->scale < MIN_SCALE)
			fdf->scale = MIN_SCALE;
	}
	draw_map(fdf, fdf->params);
	return (0);
}

//info --> cleans up everything when the window is closed

int	clean_up(t_fdf *fdf)
{
	int	i;

	if (fdf->map)
	{
		i = 0;
		while (i < fdf->height)
		{
			free(fdf->map[i]);
			i++;
		}
		free(fdf->map);
	}
	if (fdf->params)
		free(fdf->params);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(0);
}
