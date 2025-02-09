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

//info --> checks if the args are the right nbr and type

char *check_args(int ac, char **av)
{
	char	**file_type;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Try ./fdf *.fdf\n", 2);
		exit(EXIT_FAILURE);
	}
	file_type = ft_split(av[1], '.');
	if (ft_strncmp(file_type[1], "fdf", 3) == 0)
	{
		free_arrays((void **)file_type);
		return(av[1]);
	}
	else
	{
		ft_putstr_fd("Error: file must be .fdf type\n", 2);
		free_arrays((void **)file_type);
		exit(EXIT_FAILURE);
	}
}

//info --> counts the nbrs in a line, ignoring spaces and 
//			handling nbrs with multiple digits

int	ft_count_nbr(char *str)
{
	int	i;
	int count;
	int	in_nbr;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	in_nbr = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			if (in_nbr == 0)
			{
				in_nbr = 1;
				count++;
			}
		}
		else
			in_nbr = 0;
		i++;
	}
	return (count);
}

int	get_z_value(t_fdf *fdf, int x, int y)
{
	if (x < 0 || y < 0 || y >= fdf->height || x >= fdf->width)
		errors("Error: Out of bounds", NULL, 0);
	return (fdf->map[y][x]);
}

//info --> draws a pixel  and colors it

void	pixel_put(t_fdf *fdf, int x, int y, int color)
{
    char *pxl;

    if (x < 0 || y < 0 || x >= DISP_X || y >= DISP_Y)
        return;
    pxl = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
    *(unsigned int *)pxl = color;
    printf("Pixel drawn at (%d, %d) with color %X\n", x, y, color);
}
