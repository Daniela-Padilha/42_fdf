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

#include "include/fdf.h"

void	fdf(int ac, char **av)
{
	int		fd;
	char	**file_type;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Too many arguments", 2);
		exit(EXIT_FAILURE);
	}
	file_type = ft_split(av[1], '.');
	if (ft_strncmp(file_type, "fdf", 3) == 0)
		fd = open(av[1], RDONLY);
	else
	{
		ft_putstr_fd("Error: file bust be .fdf type", 2);
		exit(EXIT_FAILURE);
	}

}
