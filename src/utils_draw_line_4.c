/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:11 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 20:04:42 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tab_v4(t_data *data, float *p1, float *p2)
{
	int		i;
	float	size;
	float	x;
	float	y;
	float	z;

	size = p2[1] - p1[1];
	i = 0;
	while (++i < size)
	{
		x = p2[0] + (float)i;
		y = p2[1] - (float)i;
		z = ((float)i / size) * (p1[2] - p2[2]) + p2[2];
		draw_pt(data, x, y, z);
	}
}

void	tab_v5(t_data *data, float *p1, float *p2)
{
	int		i;
	float	size;
	float	x;
	float	y;
	float	z;

	size = p1[1] - p2[1];
	i = 0;
	while (++i < size)
	{
		y = p1[1] - (float)i;
		x = ft_get_x(ft_a_b_line(p1, p2), y);
		z = ((float)i / size) * (p2[2] - p1[2]) + p1[2];
		draw_pt(data, x, y, z);
	}
}

void	tab_v6(t_data *data, float *p1, float *p2)
{
	int		i;
	float	size;
	float	x;
	float	y;
	float	z;

	size = p2[0] - p1[0];
	i = 0;
	while (++i < size)
	{
		x = p1[0] + (float)i;
		y = ft_get_y(ft_a_b_line(p1, p2), x);
		z = ((float)i / size) * (p2[2] - p1[2]) + p1[2];
		draw_pt(data, x, y, z);
	}
}

void	ft_line_tp(t_data *data, float *p1, float *p2, float tan)
{
	if (tan == 1)
	{
		if (ft_smallest(p1[0], p2[0]) == 1)
			tab_v1(data, p1, p2);
		else
			tab_v1(data, p2, p1);
	}
	else if (tan > 1)
	{
		if (ft_smallest(p1[0], p2[0]) == 1)
			tab_v2(data, p1, p2);
		else
			tab_v2(data, p2, p1);
	}
	else if (tan < 1)
	{
		if (ft_smallest(p1[0], p2[0]) == 1)
			tab_v3(data, p1, p2);
		else
			tab_v3(data, p2, p1);
	}
}

void	ft_line_tn(t_data *data, float *p1, float *p2, float tan)
{
	if (tan == -1)
	{
		if (ft_smallest(p1[0], p2[0]) == 2)
			tab_v4(data, p1, p2);
		else
			tab_v4(data, p2, p1);
	}
	else if (tan < -1)
	{
		if (ft_smallest(p1[0], p2[0]) == 1)
			tab_v5(data, p1, p2);
		else
			tab_v5(data, p2, p1);
	}
	else if (tan > -1)
	{
		if (ft_smallest(p1[0], p2[0]) == 1)
			tab_v6(data, p1, p2);
		else
			tab_v6(data, p2, p1);
	}
}
