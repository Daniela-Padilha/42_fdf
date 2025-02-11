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
//info --> draw diagonal lines when possible

void	draw_diagon(t_fdf *fdf, t_line *params, t_point *current, t_point *next)
{
	next->x = current->x + 1;
	next->y = current->y + 1;
	next->z = get_z_value(fdf, next->x, next->y);
	draw_transformed_line(fdf, params, current, next);
}