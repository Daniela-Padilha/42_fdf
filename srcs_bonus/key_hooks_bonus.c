/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:14:18 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 12:14:18 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

//info --> handle key events

int	handle_keys(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		clean_up(fdf);
	zoom(keycode, fdf);
	angle(keycode, fdf);
	translate(keycode, fdf);
	draw_map(fdf, fdf->params);
	return (0);
}

void	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
	{
		fdf->scale *= ZOOM_FACTOR;
		if (fdf->scale > MAX_SCALE)
			fdf->scale = MAX_SCALE;
	}
	else if (keycode == KEY_MINUS)
	{
		fdf->scale /= ZOOM_FACTOR;
		if (fdf->scale < MIN_SCALE)
			fdf->scale = MIN_SCALE;
	}
}

void	angle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		fdf->angle -= 0.1;
	else if (keycode == KEY_X)
		fdf->angle += 0.1;
}

void	translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_A)
		fdf->translate_x -= 2;
	else if (keycode == KEY_D)
		fdf->translate_x += 2;
	if (keycode == KEY_W)
		fdf->translate_y -= 2;
	else if (keycode == KEY_S)
		fdf->translate_y += 2;
	if (keycode == UP_ARROW)
		fdf->translate_z += 2;
	else if (keycode == DOWN_ARROW)
		fdf->translate_z -= 2;
}
