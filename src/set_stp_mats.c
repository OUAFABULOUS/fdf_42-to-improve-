/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stp_mats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:50:02 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 19:59:15 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_sm(float *sm, t_map *map)
{
	int		i;

	i = 0;
	sm[i] = map->sx;
	while (++i < 5)
		sm[i] = 0;
	sm[i] = map->sy;
	while (++i < 10)
		sm[i] = 0;
	sm[i] = map->sz;
	while (++i < 15)
		sm[i] = 0;
	sm[i] = 1;
}

void	set_tm(float *tm, t_map *map)
{
	int		i;

	i = -1;
	tm[++i] = 1;
	while (++i < 3)
		tm[i] = 0;
	tm[i] = map->tx;
	tm[++i] = 0;
	tm[++i] = 1;
	while (++i < 7)
		tm[i] = 0;
	tm[i] = map->ty;
	while (++i < 10)
		tm[i] = 0;
	tm[i] = 1;
	tm[++i] = map->tz;
	while (++i < 15)
		tm[i] = 0;
	tm[i] = 1;
}

void	set_gm(float *gm, t_map *map)
{
	float	rsm[16];

	x_2_mat(rsm, map->rm, map->sm);
	x_2_mat(gm, map->tm, rsm);
}
