/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:49:13 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/28 17:38:06 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	init_map(t_proj *proj, t_map *map, char *argv1)
{
	map->iso = 1;
	map->win_h = WIN_H;
	map->win_w = WIN_W;
	map->coords = file_2_cloud(argv1, map);
	init_srt(map);
	ft_scale(map, (float)(map->i), (float)(map->j));
	set_pm_ba(map->pm_ba);
	set_sm(map->sm, map);
	set_tm(map->tm, map);
	set_rm(map->rm, map);
	set_gm(map->gm, map);
	map->t_coords = trans_array(map);
	if (map->iso == 0)
		map->p_coords = NULL;
	if (map->iso == 1)
	{
		map->pp_coords = proj_array_ba(map);
		init_proj(proj, map);
		set_pm(map->pm, proj);
		map->p_coords = proj_array(map);
	}
	map->min = ft_min(map->coords, map->i, map->j, 2);
	map->max = ft_max(map->coords, map->i, map->j, 2);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->i * map->j)
	{
		if (map->coords[i])
			free(map->coords[i]);
		if (map->t_coords && (map->t_coords)[i])
			free(map->t_coords[i]);
		if (map->p_coords && (map->p_coords)[i])
			free(map->p_coords[i]);
		i++;
	}
	free(map->coords);
	free(map->t_coords);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_W);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp),
			&(mlx->l_length), &(mlx->end));
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

void	init_data(t_data *data, t_map *map, char *argv1, t_mlx *mlx)
{
	t_proj	proj;

	init_map(&proj, map, argv1);
	init_mlx(mlx);
	data->map = map;
	data->mlx = mlx;
	data->i_add = (unsigned int *)(mlx->addr);
}
