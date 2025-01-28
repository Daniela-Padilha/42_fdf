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
	int		fd;
	char	**file_type;
	t_fdf	fdf;

	if (ac > 2)
	{
		ft_putstr_fd("Error: Try ./fdf *.fdf\n", 2);
		exit(EXIT_FAILURE);
	}
	file_type = ft_split(av[1], '.');
	if (ft_strncmp(file_type[1], "fdf", 3) == 0)
		fd = open(av[1], O_RDONLY);
	else
	{
		ft_putstr_fd("Error: file bust be .fdf type\n", 2);
		exit(EXIT_FAILURE);
	}
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 700, 500, "FdF");
	mlx_pixel_put(fdf.mlx, fdf.win, 700/2, 500/2, 0xFFFFFFFF);
	mlx_hook(fdf.win, 2, 1L<<0, handle_keys, &fdf);
	mlx_hook(fdf.win, 17, 0L, close_window, &fdf);
	mlx_loop(fdf.mlx);
	close(fd);
	return (0);
}
