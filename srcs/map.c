/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:41:52 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/29 22:41:52 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	**read_file(t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**matrix_char;

	fd = open(fdf->map, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 1);
	matrix_char = ft_split(line, ' ');
	if (!matrix_char)
		return (close(fd), free(line), 1);
	return (matrix_char);
}

int	**create_matrix(t_fdf *fdf)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	j = 0;
	matrix = (int **)malloc(fdf->map_height * sizeof(int *));
	*matrix = (int *)malloc(fdf->map_width * sizeof(int));
	while (fdf->matrix_char[i][j] && i < fdf.map_height && j < fdf.map_width)
	{
		matrix[i][j] = ft_atoi(fdf->matrix_char[i][j]);
		i++;
	}
	free_arrays(fdf->matrix_char);
	return (matrix);
}

int	map_height(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->matrix_char[i][0])
		i++;
	return (i);
}

int	map_width(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->matrix_char[0][i])
		i++;
	return (i);
}
