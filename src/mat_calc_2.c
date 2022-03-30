/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_calc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:04:51 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 10:58:47 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	**trans_array(t_map *map)
{
	return (mat_x_arr(map->gm, map->coords, map));
}

float	**proj_array_ba(t_map *map)
{
	return (mat_x_arr(map->pm_ba, map->t_coords, map));
}

float	**proj_array(t_map *map)
{
	return (mat_x_arr(map->pm, map->t_coords, map));
}
