/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:59 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:59 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

//info --> reads the file and stores the numbers in a 2D array

int	**read_file(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		**map;
	int		i;

	fd = open(fdf->map_name, O_RDONLY);
	if (fd == -1)
		errors("Error: opening file failed", NULL, 1);
	fdf->height = map_height(fdf);
	map = (int **)malloc(fdf->height * sizeof(int *));
	if (!map)
	{
		close(fd);
		errors("Error: mem allocation failed", NULL, 1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i++] = line_to_ints(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

//info --> converts the line into an array of ints

int	*line_to_ints(char *line)
{
	char	**split_line;
	int		*data;
	int		i;
	int		width;

	split_line = ft_split(line, ' ');
	width = 0;
	while (split_line[width])
		width++;
	data = (int *)malloc(width * sizeof(int));
	if (!data)
	{
		free(split_line);
		errors("Error: mem allocation failed", NULL, 1);
	}
	i = 0;
	while (split_line[i])
	{
		data[i] = ft_atoi(split_line[i]);
		i++;
	}
	free_arrays((void **)split_line);
	return (data);
}

//info --> gets the maximum height of the map (nbr of rows)

int	map_height(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		n_lines;

	fd = open(fdf->map_name, O_RDONLY);
	if (fd == -1)
		errors("Error: opening file failed", NULL, 1);
	n_lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		n_lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (n_lines == 0)
	{
		free(line),
		close(fd);
		errors("Error: map is empty", NULL, 1);
	}
	free(line);
	close(fd);
	return (n_lines);
}

//info --> gets the maximum width of the map (nbr of columns)

int	map_width(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		line_len;
	int		max;

	fd = open(fdf->map_name, O_RDONLY);
	if (fd == -1)
		errors("Error: opening file failed", NULL, 1);
	max = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = ft_count_nbr(line, 0, 0, 0);
		if (line_len > max)
			max = line_len;
		free(line);
		line = get_next_line(fd);
	}
	if (max == 0)
	{
		close(fd);
		errors("Error: map is empty", NULL, 1);
	}
	close(fd);
	return (max);
}
