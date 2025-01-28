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


char* combine_strings(char* str1, char* str2)
{
	char* newstr = ft_strjoin(str1, str2);
	free(str1); free(str2);
	return newstr;
}