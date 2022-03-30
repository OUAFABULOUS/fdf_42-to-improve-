/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:57:37 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 10:55:12 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_proj(t_proj *proj, t_map *map)
{
	float	s1;
	float	s2;
	float	**coords;

	coords = map->pp_coords;
	proj->l = ft_max(coords, map->i, map->j, 0)
		- ft_min(coords, map->i, map->j, 0);
	proj->h = ft_max(coords, map->i, map->j, 1)
		- ft_min(coords, map->i, map->j, 1);
	proj->center[0] = ft_min(coords, map->i, map->j, 0) + proj->l / 2;
	proj->center[1] = ft_min(coords, map->i, map->j, 1) + proj->h / 2;
	proj->tx = -ft_min(coords, map->i, map->j, 0);
	proj->ty = -ft_min(coords, map->i, map->j, 1);
	s1 = (float)(WIN_W - IMG_0_0) / proj->l;
	s2 = (float)(WIN_H - IMG_0_1) / proj->h;
	if (s1 <= s2)
	{
		proj->sx = s1;
		proj->sy = s1;
	}
	else
	{
		map->sx = s2 * 0.8;
		map->sy = s2 * 0.8;
	}
}

void	init_srt(t_map *map)
{
	map->sx = 1;
	map->sy = 1;
	map->sz = 1;
	map->rx = 0;
	map->ry = 0;
	map->rz = 0;
	map->tx = 0;
	map->ty = 0;
	map->tz = 0;
}
