/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:34:12 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 19:54:49 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_tan(float *p1, float *p2)
{
	float	tan;

	tan = (p2[1] - p1[1]) / (p2[0] - p1[0]);
	return (tan);
}

void	tab_1(t_data *data, float *p1, float *p2, char ij)
{
	int		k;
	float	size;
	float	x;
	float	y;
	float	z;

	size = get_line_size(p1, p2, ij);
	k = 0;
	while (++k < ft_round(size))
	{
		z = ((float)k / size) * (p2[2] - p1[2]) + p1[2];
		if (ij == 'i')
		{
			x = p1[0];
			y = p1[1] + (float)k;
		}
		else if (ij == 'j')
		{
			x = p1[0] + (float)k;
			y = p1[1];
		}
		draw_pt(data, x, y, z);
	}
}

void	ft_line_same_x(t_data *data, float *p1, float *p2)
{
	if (p2[1] - p1[1] > 0)
		tab_1(data, p1, p2, 'i');
	else if (p2[1] - p1[1] < 0)
		tab_1(data, p2, p1, 'i');
}

void	ft_line_same_y(t_data *data, float *p1, float *p2)
{
	if (p2[0] - p1[0] > 0)
		tab_1(data, p1, p2, 'j');
	else if (p2[0] - p1[0] < 0)
		tab_1(data, p2, p1, 'j');
}
