/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:13:27 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 11:46:40 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_min(float **tab, int i, int j, int xyz)
{
	float	min;
	int		k;
	int		size;

	k = 0;
	size = i * j;
	min = tab[k][xyz];
	while (k < size)
	{
		if (tab[k][xyz] <= min)
			min = tab[k][xyz];
		k++;
	}
	return (min);
}

float	ft_max(float **tab, int i, int j, int xyz)
{
	float	max;
	int		k;
	int		size;

	k = 0;
	size = i * j;
	max = tab[k][xyz];
	while (k < size)
	{
		if (tab[k][xyz] >= max)
			max = tab[k][xyz];
		k++;
	}
	return (max);
}

void	ft_translate(t_map *map, float tx, float ty)
{
	map->tx += tx;
	map->ty += ty;
}

void	ft_scale(t_map *map, float l, float h)
{
	float	sx;
	float	sy;

	sx = (float)(WIN_W - IMG_0_0) / l;
	sy = (float)(WIN_H - IMG_0_1) / h;
	if (sx <= sy)
	{
		map->sx *= sx;
		map->sy *= sx;
	}
	else
	{
		map->sx *= sy;
		map->sy *= sy;
	}
	map->sz = map->sx / 10;
}

void	free_data(t_data *data)
{
	free_map(data->map);
	free_mlx(data->mlx);
}
