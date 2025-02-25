/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:09:16 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/28 21:09:16 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//info --> uses the handle functions with hooks

int	handle_events(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, handle_keys, fdf);
	mlx_hook(fdf->win, 17, 0L, clean_up, fdf);
	return (0);
}

//info --> handle key events

int	handle_keys(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		clean_up(fdf);
	draw_map(fdf, fdf->params);
	return (0);
}

//info --> cleans up everything when the window is closed

int	clean_up(t_fdf *fdf)
{
	int	i;

	if (fdf->map != NULL)
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
