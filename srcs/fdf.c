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

// int	loop_hook_function(void *param)
// {
//     t_fdf *fdf = (t_fdf *)param;
//     draw_map(fdf, BLUE);
//     return 0;
// }


int	main(int ac, char **av)
{
	t_fdf	fdf;
	
	fdf.map_name = check_args(ac, av);
	fdf_init(&fdf);
	handle_events(&fdf);
	draw_map(&fdf, fdf.params);
	mlx_loop(fdf.mlx);
	return (0);
}
