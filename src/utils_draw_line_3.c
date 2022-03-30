/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:46:43 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/24 17:07:55 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	*ft_a_b_line(float *p1, float *p2)
{
	float	a;
	float	b;
	float	*res;

	a = (p2[1] - p1[1]) / (p2[0] - p1[0]);
	b = p2[1] - a * p2[0];
	res = malloc(2 * sizeof(float));
	res[0] = a;
	res[1] = b;
	return (res);
}

float	ft_get_x(float *params, float y)
{
	float	x;

	x = (y - params[1]) / params[0];
	free(params);
	return (x);
}

float	ft_get_y(float *params, float x)
{
	float	y;

	y = params[0] * x + params[1];
	free(params);
	return (y);
}
