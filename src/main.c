/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:17:03 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 12:50:05 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_data	data;

	if (argc == 2)
	{
		init_data(&data, &map, argv[1], &mlx);
		display(&data);
		mlx_hook((&mlx)->win, 2, 1L << 0, key_hook, &data);
		mlx_hook((&mlx)->win, 17, 1L << 17, ft_close, &data);
		mlx_loop((&mlx)->mlx);
		free((&data)->mlx->mlx);
		exit(0);
	}
	else
		display_error("Check arguments' number!\n");
	return (0);
}
