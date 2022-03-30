/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:36:29 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/23 21:03:42 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	get_grad(float z, int min, int max)
{
	float	spectrum;
	float	z_per;

	spectrum = max - min;
	z_per = (z - min) / spectrum;
	return (z_per);
}

static t_color	*z_2_col(float z_per)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	color->r = z_per;
	color->g = 0;
	color->b = 1 - z_per;
	return (color);
}

static UINT	rgb_2_hx(t_color *color)
{
	unsigned int	hex_col;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = ft_round(color->r * 255) << 16;
	green = ft_round(color->g * 255) << 8;
	blue = ft_round(color->b * 255);
	hex_col = (unsigned int)(red + green + blue);
	free(color);
	return (hex_col);
}

UINT	get_color(t_map *map, float z)
{
	return (rgb_2_hx(z_2_col(get_grad(z, map->min, map->max))));
}
