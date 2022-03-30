/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_line_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:42 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 20:04:56 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_line_size(float *p1, float *p2, char ij)
{
	float	size;

	if (ij == 'i')
		size = p2[1] - p1[1];
	else if (ij == 'j')
		size = p2[0] - p1[0];
	return (size);
}
