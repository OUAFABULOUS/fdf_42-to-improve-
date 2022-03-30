/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_2_cloud_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:15:56 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 14:21:40 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	exit (0);
}

void	*free_uncompleted_tab(float **atof, float ***tab, int i)
{
	int	k;

	k = 0;
	free(*atof);
	if (i == 0)
		free((*tab)[0]);
	while (k < i)
	{
		free((*tab)[k]);
		k++;
	}
	free(*tab);
	return (NULL);
}

float	**file_2_cloud(char *argv1, t_map *map)
{
	char	***tab_char;
	float	**mat;
	float	**cloud;
	int		i;

	i = -1;
	tab_char = char_tab(argv1, map);
	if (!tab_char)
		display_error("Something is wrong with your file\n");
	mat = float_tab(tab_char, map);
	if (!mat)
		display_error("Your file doesn't contain digits only\n");
	cloud = mat_2_cloud(mat, map);
	while (++i < map->j)
		free(mat[i]);
	free(mat);
	if (!cloud)
		display_error("Error while creating the points' cloud\n");
	return (cloud);
}
