/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_r_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:14:38 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 19:56:50 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	deg_2_rad(float deg)
{
	return ((M_PI * deg) / 180);
}

void	set_rx(float *mrx, t_map *map)
{
	int		i;

	i = 0;
	mrx[i] = 1;
	while (++i < 5)
		mrx[i] = 0;
	mrx[i] = cos(deg_2_rad(map->rx));
	mrx[++i] = -sin(deg_2_rad(map->rx));
	mrx[++i] = 0;
	mrx[++i] = 0;
	mrx[++i] = sin(deg_2_rad(map->rx));
	mrx[++i] = cos(deg_2_rad(map->rx));
	while (++i < 15)
		mrx[i] = 0;
	mrx[i] = 1;
}

void	set_ry(float *mry, t_map *map)
{
	int		i;

	i = 0;
	mry[i] = cos(deg_2_rad(map->ry));
	mry[++i] = 0;
	mry[++i] = sin(deg_2_rad(map->ry));
	while (++i < 5)
		mry[i] = 0;
	mry[i] = 1;
	mry[++i] = 0;
	mry[++i] = 0;
	mry[++i] = -sin(deg_2_rad(map->ry));
	mry[++i] = 0;
	mry[++i] = cos(deg_2_rad(map->ry));
	while (++i < 15)
		mry[i] = 0;
	mry[i] = 1;
}

void	set_rz(float *mrz, t_map *map)
{
	int	i;

	i = 0;
	mrz[i] = cos(deg_2_rad(map->rz));
	mrz[++i] = -sin(deg_2_rad(map->rz));
	mrz[++i] = 0;
	mrz[++i] = 0;
	mrz[++i] = sin(deg_2_rad(map->rz));
	mrz[++i] = cos(deg_2_rad(map->rz));
	while (++i < 10)
		mrz[i] = 0;
	mrz[i] = 1;
	while (++i < 15)
		mrz[i] = 0;
	mrz[i] = 1;
}

void	set_rm(float *rm, t_map *map)
{
	float	mrx[16];
	float	mry[16];
	float	mrz[16];
	float	mryx[16];

	set_rx(mrx, map);
	set_ry(mry, map);
	set_rz(mrz, map);
	x_2_mat(mryx, mry, mrx);
	x_2_mat(rm, mrz, mryx);
}
