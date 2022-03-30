/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:34:14 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 19:57:22 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	display(t_data *data)
{
	t_map	*map;
	t_mlx	*mlx;
	int		i;
	int		size;
	float	**coords;

	map = data->map;
	mlx = data->mlx;
	i = 0;
	size = map->i * map->j;
	ft_bzero(&(data->i_add), WIN_H * WIN_W);
	if (!map->iso)
		coords = map->t_coords;
	else
		coords = map->p_coords;
	while (i < size)
	{
		draw_pt(data, coords[i][0], coords[i][1], map->coords[i][2]);
		draw_line(data, coords, i);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, IMG_0_0, IMG_0_1);
	draw_menu(data);
}
