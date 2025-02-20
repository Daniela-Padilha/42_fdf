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
//			handling nbrs with multiple digits, and colors

int	ft_count_nbr(char *str, int i, int count, int in_nbr)
{
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
		{
			if (in_nbr == 0)
			{
				in_nbr = 1;
				count++;
			}
		}
		else if (str[i] == ',')
		{
			while (str[i] && !ft_is_space(str[i]))
				i++;
			continue ;
		}
		else if (ft_is_space(str[i]))
			in_nbr = 0;
		i++;
	}
	return (count);
}

//info --> check if a string is is number, letters or symbols

int	ft_str_isalnum(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 33 && c[i] <= 126)
			i++;
		else
			return (0);
	}
	return (1);
}
