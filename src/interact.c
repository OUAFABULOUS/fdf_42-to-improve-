/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:25:43 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/29 20:17:36 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

int	ft_close(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void	free_2_reinit_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->i * map->j)
	{
		if (map->t_coords && (map->t_coords)[i])
			free_int_point(&((map->t_coords)[i]));
		if (map->p_coords && (map->p_coords)[i])
			free_int_point(&((map->p_coords)[i]));
		i++;
	}
	if (map->t_coords)
	{
		free(map->t_coords);
		map->t_coords = NULL;
	}
	if (map->p_coords)
	{
		free(map->p_coords);
		map->p_coords = NULL;
	}
}

void	reinitialize_map(t_map *map, int centralize, int op)
{
	if (!centralize)
	{
		set_sm(map->sm, map);
		set_tm(map->tm, map);
		set_rm(map->rm, map);
		set_gm(map->gm, map);
		free_double_float(map->t_coords, map->i * map->j);
		map->t_coords = trans_array(map);
	}
	if (centralize)
	{
		if (op)
			reinitialize_rot(map);
		if (!op)
			reinitialize_zoom(map);
	}
	if (!map->iso)
		map->p_coords = NULL;
	if (map->iso)
		map->p_coords = proj_array(map);
}

void	ft_move(int key, t_data *data)
{
	t_map	*map;

	map = data->map;
	if (key == D)
		map->tx -= 10;
	if (key == F)
		map->tx += 10;
	if (key == R)
		map->ty -= 10;
	if (key == C)
		map->ty += 10;
}

void	ft_zoom(int key, t_data *data, int *centralize, int *op)
{
	t_map	*map;

	*op = 0;
	*centralize = 1;
	map = data->map;
	if (key == UP)
	{
		map->sx *= 1.1;
		map->sy *= 1.1;
		map->sz *= 1.1;
		map->tx = - (map->i / 2) * map->sx;
		map->ty = - (map->j / 2) * map->sx;
	}
	if (key == DOWN)
	{
		map->sx *= 0.9;
		map->sy *= 0.9;
		map->sz *= 0.9;
		map->tx = - (map->i / 2) * map->sx;
		map->ty = - (map->j / 2) * map->sx;
	}
}
