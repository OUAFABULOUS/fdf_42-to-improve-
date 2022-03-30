/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_2_cloud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:24:11 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 13:00:04 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	***char_tab(char *argv1, t_map *map)
{
	char	*file;
	char	**first_tab;
	char	***res;

	file = ft_open_store(argv1);
	if (!file)
		return (NULL);
	if (!*file)
	{
		free(file);
		return (NULL);
	}
	first_tab = ft_split(file, "\n");
	free(file);
	if (!first_tab)
		return (NULL);
	if (!*first_tab)
	{
		free(first_tab);
		return (NULL);
	}
	res = ft_ultimate_split(first_tab);
	map->j = ft_count_elem(first_tab);
	free_split(first_tab);
	return (res);
}

static int	check_tab(char ***char_tab)
{
	if (!char_tab)
		return (0);
	if (!*char_tab)
	{
		free(char_tab);
		return (0);
	}
	if (!**char_tab)
	{
		ft_free_triple(char_tab);
		return (0);
	}
	return (1);
}

float	**float_tab(char ***char_tab, t_map *map)
{
	float	**res;

	if (!check_tab(char_tab))
		return (NULL);
	map->i = ft_count_elem(char_tab[0]);
	if (!ft_check_lines(char_tab, map->i, map->j))
	{
		ft_free_triple(char_tab);
		return (NULL);
	}
	res = ft_float_tab(char_tab, map->j, map->i);
	ft_free_triple(char_tab);
	if (!res)
		return (NULL);
	if (!*res)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

static void	ft_fill_tab(float **from, float **to, int x, int y)
{
	(*to)[0] = (float)x;
	(*to)[1] = (float)y;
	(*to)[2] = (float)from[y][x];
	(*to)[3] = (float)1;
}

float	**mat_2_cloud(float **mat, t_map *map)
{
	float	**ret;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	ret = malloc((map->i * map->j) * sizeof(float *));
	if (!ret)
		return (NULL);
	while (j < map->j)
	{
		i = 0;
		while (i < map->i)
		{
			ret[k] = malloc (4 * sizeof(float));
			if (!ret[k])
				return (NULL);
			ft_fill_tab(mat, &ret[k], i, j);
			k++;
			i++;
		}
		j++;
	}
	return (ret);
}
