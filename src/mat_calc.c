/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:11:16 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/29 20:13:59 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	x_2_mat(float *res, float *mat_1, float *mat_2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			res[j * 4 + i] = 0;
			k = 0;
			while (k < 4)
			{
				res[j * 4 + i] += mat_1[j * 4 + k] * mat_2[i + 4 * k];
				k++;
			}
			i++;
		}
		j++;
	}
}

static void	mat_x_vec(float *t_coords, float *matrix, float *coords)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		t_coords[i] = 0;
		j = 0;
		while (j < 4)
		{
			t_coords[i] += matrix[j + i * 4] * coords[j];
			j++;
		}
		i++;
	}
}

float	**mat_x_arr(float *mat, float **coords, t_map *map)
{
	int		size;
	int		i;
	float	**t_coords;

	size = map->i * map->j;
	t_coords = malloc(size * sizeof(float *));
	i = 0;
	while (i < size)
	{
		t_coords[i] = malloc(4 * sizeof(float));
		mat_x_vec(t_coords[i], mat, coords[i]);
		i++;
	}
	return (t_coords);
}

int	ft_round(float to_round)
{
	if (to_round - (int)to_round >= 0.5)
		return ((int)to_round + 1);
	else
		return ((int)to_round);
}

void	round_arr(t_map *map, float **coords)
{
	int	i;
	int	j;
	int	size;

	size = map->i * map->j;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 4)
		{
			coords[i][j] = ft_round(coords[i][j]);
			j++;
		}
		i++;
	}
}
