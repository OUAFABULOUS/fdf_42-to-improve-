/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:52:23 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 19:06:50 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_line_1(t_line *line, t_map *map, float **coords, int i)
{
	line->p1[0] = coords[i][0];
	line->p1[1] = coords[i][1];
	line->p1[2] = map->coords[i][2];
	line->p1[3] = 1;
	line->p2[0] = coords[i + 1][0];
	line->p2[1] = coords[i + 1][1];
	line->p2[2] = map->coords[i + 1][2];
	line->p2[3] = 1;
}

void	init_line_2(t_line *line, t_map *map, float **coords, int i)
{
	line->p1[0] = coords[i][0];
	line->p1[1] = coords[i][1];
	line->p1[2] = map->coords[i][2];
	line->p1[3] = 1;
	line->p2[0] = coords[i + map->i][0];
	line->p2[1] = coords[i + map->i][1];
	line->p2[2] = map->coords[i + map->i][2];
	line->p2[3] = 1;
}
