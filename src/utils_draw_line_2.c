/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:53:50 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/03 13:49:31 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_smallest(float v1, float v2)
{
	if (v2 > v1)
		return (1);
	else
		return (2);
}

void	tab_v1(t_data *data, float *p1, float *p2)
{
	int		i;
	float	size;
	float	x;
	float	y;
	float	z;

	size = p2[1] - p1[1];
	i = 0;
	while (++i < ft_round(size))
	{
		x = p1[0] + (float)i;
		y = p1[1] + (float)i;
		z = (i / size) * (p2[2] - p1[2]) + p1[2];
		draw_pt(data, x, y, z);
	}
}

void	tab_v2(t_data *data, float *p1, float *p2)
{
	int		i;
	float	size;
	float	x;
	float	y;
	float	z;

	size = p2[1] - p1[1];
	i = 0;
	while (++i < ft_round(size))
	{
		y = p1[1] + (float)i;
		x = ft_get_x(ft_a_b_line(p1, p2), y);
		z = (i / size) * (p2[2] - p1[2]) + p1[2];
		draw_pt(data, x, y, z);
	}
}

void	tab_v3(t_data *data, float *p1, float *p2)
{
	int		i;
	float	size;
	float	x;
	float	y;
	float	z;

	size = p2[0] - p1[0];
	i = 0;
	while (++i < ft_round(size))
	{
		x = p1[0] + (float)i;
		y = ft_get_y(ft_a_b_line(p1, p2), x);
		z = (i / size) * (p2[2] - p1[2]) + p1[2];
		draw_pt(data, x, y, z);
	}
}
