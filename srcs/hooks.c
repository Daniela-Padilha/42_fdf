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

int	handle_events(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L<<0, handle_keys, fdf);
	mlx_hook(fdf->win, 17, 0L, close_window, fdf);
	return(0);
}

int	close_window(t_fdf *fdf)
{
	if (fdf->win)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		fdf->win = NULL;
	}
	exit(0);
	return (0);
}

int	handle_keys(int keycode, t_fdf *fdf)
{
	if(keycode == KEY_ESC)
		close_window(fdf);
	return (0);
}

