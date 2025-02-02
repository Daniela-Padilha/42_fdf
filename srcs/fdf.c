/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:03:33 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/28 16:03:33 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.in_x = 3;
	fdf.in_y = 3;
	fdf.map_name = check_args(ac, av);
	fdf_init(&fdf);
	read_file(&fdf);
	ft_printf("(%i, %i, %i)\n", fdf.in_x, fdf.in_y, fdf.z);
	draw_map(&fdf, BLUE);
	handle_events(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
