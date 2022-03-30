/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:41:15 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/03 13:47:09 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	draw_menu(t_data *data)
{
	int		y;
	t_mlx	*t_mlx;
	void	*mlx;
	void	*win;

	t_mlx = data->mlx;
	mlx = t_mlx->mlx;
	win = t_mlx->win;
	y = 0;
	mlx_string_put(mlx, win, 15, y += 15, WHITE, "Controls:");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Reset : SPACE");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Move: D, F, R, C");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Zoom: Arrows");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Rotate:");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  x (+ / -): U / I");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  y (+ / -): J / K");
	mlx_string_put(mlx, win, 30, y += 25, WHITE, "  z (+ / -): N / M");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "Toggle Perspective: P");
	mlx_string_put(mlx, win, 15, y += 25, WHITE, "(Isometric and Parallel)");
}
