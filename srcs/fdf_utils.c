/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:29:43 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/28 17:29:43 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char* combine_strings(char* str1, char* str2)
{
	char* newstr = ft_strjoin(str1, str2);
	free(str1); free(str2);
	return newstr;
}

void	fdf_init(t_fdf *fdf)
{
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 700, 500, "FdF");
	fdf.map = check_args(ac, av);
	fdf.matrix_char = read_file(fdf);
	fdf.map_height = map_height(fdf);
	fdf.map_width = map_width(fdf);
	fdf.matrix = 
}


char *check_args(int ac, char **av)
{
	int		fd;
	char	**file_type;

	if (ac > 2)
	{
		ft_putstr_fd("Error: Try ./fdf *.fdf\n", 2);
		exit(EXIT_FAILURE);
	}
	file_type = ft_split(av[1], '.');
	if (ft_strncmp(file_type[1], "fdf", 3) == 0)
	{
		free_arrays(file_type);
		return(av[1]);
	}
	else
	{
		ft_putstr_fd("Error: file must be .fdf type\n", 2);
		free_arrays(file_type);
		exit(EXIT_FAILURE);
	}
}
