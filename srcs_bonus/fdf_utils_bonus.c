/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:17 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/02/20 11:26:17 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

//info --> checks if the args are the right nbr and type

char	*check_args(int ac, char **av)
{
	char	**file_type;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Try ./fdf *.fdf\n", 2);
		exit(EXIT_FAILURE);
	}
	file_type = ft_split(av[1], '.');
	if (!file_type[1] || !ft_str_isalnum(file_type[0]))
	{
		ft_putstr_fd("Error: file must be .fdf type\n", 2);
		free_arrays((void **)file_type);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(file_type[1], "fdf", 3) == 0)
	{
		free_arrays((void **)file_type);
		return (av[1]);
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
	int	count;
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
//info --> check if a string is alphanumeric only

int	ft_str_isalnum(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (ft_isalpha(c[i]) || ft_isdigit(c[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
//info --> cleans up everything when the window is closec

int	clean_up(t_fdf *fdf)
{
	int	i;

	if (fdf->map)
	{
		i = 0;
		while (i < fdf->height)
		{
			free(fdf->map[i]);
			i++;
		}
		free(fdf->map);
	}
	if (fdf->params)
		free(fdf->params);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(0);
}
