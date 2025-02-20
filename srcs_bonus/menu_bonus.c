/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:43 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:43 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	print_menu(t_fdf *fdf)
{
	int	y;

	y = 50;
	mlx_string_put(fdf->mlx, fdf->win, 65, y, WHITE, ">>----> Controls: <----<<");
	y += 45;
	mlx_string_put(fdf->mlx, fdf->win, 30, y, WHITE, "Zoom: Scroll or +/-");
	y += 30;
	mlx_string_put(fdf->mlx, fdf->win, 30, y, WHITE, "Move X-Axis: A and D");
	y += 30;
	mlx_string_put(fdf->mlx, fdf->win, 30, y, WHITE, "Move Y-Axis: W and S");
	y += 30;
	mlx_string_put(fdf->mlx, fdf->win, 30, y, WHITE, "Move Z-Axis: Up and Down Arrows");
	y += 30;
	mlx_string_put(fdf->mlx, fdf->win, 30, y, WHITE, "Rotate: Z and X");
}
