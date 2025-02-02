/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:29:22 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/01/30 23:29:22 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//info --> reads the file and stores the numbers in a 2D array

int	**read_file(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		**map;
	int		i;

	fd = open(fdf->map_name, O_RDONLY);
	if (fd == -1)
		errors("Error: opening file failed\n");
	fdf->height = map_height(fdf);
	fdf->width = map_width(fdf);
	map = (int **)malloc(fdf->height * sizeof(int *));
	if (!map)
	{
		close(fd);
		errors("Error: mem allocation failed");
	}
	i = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		map[i++] = line_to_ints(fdf, line);
		free(line);
	}
	close(fd);
	return (map);
}

//info --> converts the line into an array of ints

int	*line_to_ints(t_fdf *fdf, char *line)
{
	char	**split_line;
	int		*data;
	int		i;

	split_line = ft_split(line, ' ');
	data = (int *)malloc(fdf->width * sizeof(int));
	if (!data)
	{
		free(split_line);
		errors("Error: mem allocation failed");
	}
	i = 0;
	while (split_line[i])
	{
		data[i] = ft_atoi(split_line[i]);
		free(split_line[i]);
		i++;
	}
	free(split_line);
	return (data);
}

//info --> gets the maximum height of the map (nbr of rows)

int	map_height(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int 	n_lines;
	
	fd = open(fdf->map_name, O_RDONLY);
	if (fd == -1)
	errors("Error: opening file failed\n");
	n_lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		n_lines++;
		free(line);
	}
	if (n_lines == 0)
	{
		close(fd);
		errors("Error: map is empty\n");
	}
	close(fd);
	return (n_lines);
}

//info --> gets the maximum width of the map (nbr of columns)

int	map_width(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int 	line_len;
	int		max;

	fd = open(fdf->map_name, O_RDONLY);
	if (fd == -1)
		errors("Error: opening file failed\n");
	max = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_len = ft_count_nbr(line);
		if (line_len > max)
			max = line_len;
		free(line);
	}
	if (max == 0)
	{
		close(fd);
		errors("Error: map is empty\n");
	}
	close(fd);
	return (max);
}

