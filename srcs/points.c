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
	while(split_line[width])
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
		close(fd);
		errors("Error: map is empty", NULL, 1);
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
		errors("Error: opening file failed", NULL, 1);
	max = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = ft_count_nbr(line);
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
void	scale_and_center(t_fdf *fdf, t_point *point)
{
	double	scale_x;
	double	scale_y;
	double scaled_x;
	double scaled_y;

	if (fdf->scale == 0)
	{
		scale_x = (double)(DISP_X * 0.75) / (fdf->width + fdf->height);
        scale_y = (double)(DISP_Y * 0.75) / ((fdf->width + fdf->height) / 2);
		fdf->scale = fmin(scale_x, scale_y);
		fdf->center_x = DISP_X / 2;
   		fdf->center_y = DISP_Y / 2;
	}
   	scaled_x = point->x * fdf->scale;
    scaled_y = point->y * fdf->scale;
	scaled_x += fdf->center_x - ((fdf->width + fdf->height) * fdf->scale / 2);
    scaled_y += fdf->center_y - ((fdf->width + fdf->height) * fdf->scale / 4);
    point->x = (int)fmax(0, fmin(scaled_x, DISP_X - 1));
    point->y = (int)fmax(0, fmin(scaled_y, DISP_Y - 1));

    // Z-coordinate scaling (if needed)
     point->z = (int)(point->z * (fdf->scale * 0.1));
	printf("After scale and center: x: %d, y: %d, z: %d\n", point->x, point->y, point->z);
}

