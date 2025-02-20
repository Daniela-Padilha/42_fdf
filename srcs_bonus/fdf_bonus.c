/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:11 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:11 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.map_name = check_args(ac, av);
	fdf_init(&fdf);
	params_init(fdf.params);
	handle_events(&fdf);
	draw_map(&fdf, fdf.params);
	mlx_loop(fdf.mlx);
	return (0);
}
