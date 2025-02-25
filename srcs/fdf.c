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

	fdf.map_name = check_args(ac, av);
	fdf_init(&fdf);
	params_init(fdf.params);
	fdf.map = read_file(&fdf, 0);
	fdf.height = map_height(&fdf);
	fdf.width = map_width(&fdf);
	handle_events(&fdf);
	draw_map(&fdf, fdf.params);
	mlx_loop(fdf.mlx);
	return (0);
}
