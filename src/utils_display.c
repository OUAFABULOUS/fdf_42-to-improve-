/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:36:12 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/28 17:37:02 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bzero(UINT **addr, int bytes)
{
	UINT	*p;
	int		i;

	p = *addr;
	i = 0;
	while (i < bytes)
	{
		p[i] = 0;
		i++;
	}
}

static int	in_canevas(int x, int y)
{
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
		return (1);
	return (0);
}

void	draw_pt(t_data *data, float x, float y, float z)
{
	int		xx;
	int		yy;
	t_map	*map;
	UINT	*i_add;

	map = data->map;
	xx = ft_round(x);
	yy = ft_round(y);
	i_add = data->i_add;
	if (in_canevas(xx, yy))
	{
		i_add[yy * WIN_W + xx] = get_color(map, z);
	}
}

void	draw_line_bis(t_data *data, float **coords, int i, char hv)
{
	t_line	line;
	float	*p1;
	float	*p2;
	float	tan;

	if (hv == 'h')
		init_line_1(&line, data->map, coords, i);
	else if (hv == 'v')
		init_line_2(&line, data->map, coords, i);
	p1 = (&line)->p1;
	p2 = (&line)->p2;
	if (p1[0] == p2[0] && p1[1] == p2[1])
		return ;
	else if (p1[0] == p2[0])
		ft_line_same_x(data, p1, p2);
	else if (p1[1] == p2[1])
		ft_line_same_y(data, p1, p2);
	else
	{
		tan = ft_tan(p1, p2);
		if (tan > 0)
			ft_line_tp(data, p1, p2, tan);
		else if (tan < 0)
			ft_line_tn(data, p1, p2, tan);
	}
}

void	draw_line(t_data *data, float **coords, int i)
{
	t_map	*map;

	map = data->map;
	if (i % map->i < map->i - 1)
		draw_line_bis(data, coords, i, 'h');
	if (i / map->i < map->j - 1)
		draw_line_bis(data, coords, i, 'v');
}
