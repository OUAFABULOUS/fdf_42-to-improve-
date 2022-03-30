/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:14:37 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/29 20:20:15 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	free_double_float(float **tab, int size)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < size)
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
	}
}

void	reinitialize_rot(t_map *map)
{
	float	**coord_prov;

	coord_prov = NULL;
	set_sm(map->sm, map);
	map->tx = 0;
	map->ty = 0;
	map->tz = 0;
	set_tm(map->tm, map);
	set_rm(map->rm, map);
	set_gm(map->gm, map);
	free_double_float(map->t_coords, map->i * map->j);
	coord_prov = mat_x_arr(map->gm, map->coords_pr_rot, map);
	map->tx = (map->i / 2) * 57;
	map->ty = (map->j / 2) * 57;
	map->tz = 0;
	set_tm(map->tm, map);
	map->t_coords = mat_x_arr(map->tm, coord_prov, map);
	free_double_float(map->coords_pr_rot, map->i * map->j);
	free_double_float(coord_prov, map->i * map->j);
}

void	reinitialize_zoom(t_map *map)
{
	float	**coord_prov;

	coord_prov = NULL;
	set_sm(map->sm, map);
	set_tm(map->tm, map);
	set_rm(map->rm, map);
	set_gm(map->gm, map);
	free_double_float(map->t_coords, map->i * map->j);
	coord_prov = trans_array(map);
	map->tx = (map->i / 2) * 57;
	map->ty = (map->j / 2) * 57;
	map->tz = 0;
	set_tm(map->tm, map);
	map->t_coords = mat_x_arr(map->tm, coord_prov, map);
	free_double_float(coord_prov, map->i * map->j);
}
