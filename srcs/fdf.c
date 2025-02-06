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

void	clean_up(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->map);
	free(fdf->delta);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.map_name = check_args(ac, av);
	fdf_init(&fdf);
	// ft_printf("%i\n", fdf.map[3][3]);
	handle_events(&fdf);
	// mlx_loop_hook(fdf.mlx, loop_hook_function, &fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
	clean_up(&fdf);
	return (0);
}
