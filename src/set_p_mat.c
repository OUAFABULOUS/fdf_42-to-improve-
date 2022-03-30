/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:08:59 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/27 22:56:16 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_pm_ba(float *pm_ba)
{
	int		i;

	i = 0;
	pm_ba[i] = cos(0.523599);
	pm_ba[++i] = -cos(0.523599);
	pm_ba[++i] = 0;
	pm_ba[++i] = 0;
	pm_ba[++i] = sin(0.523599);
	pm_ba[++i] = sin(0.523599);
	pm_ba[++i] = -1;
	pm_ba[++i] = 0;
	pm_ba[++i] = 0;
	pm_ba[++i] = 0;
	pm_ba[++i] = 1;
	while (++i < 15)
		pm_ba[i] = 0;
	pm_ba[i] = 1;
}

void	set_pm(float *pm, t_proj *proj)
{
	int		i;

	i = 0;
	pm[i] = cos(0.523599) * proj->sx;
	pm[++i] = -cos(0.523599) * proj->sx;
	pm[++i] = 0;
	pm[++i] = proj->tx * proj->sx;
	pm[++i] = sin(0.523599) * proj->sy;
	pm[++i] = sin(0.523599) * proj->sy;
	pm[++i] = -1 * proj->sy;
	pm[++i] = proj->ty * proj->sy;
	pm[++i] = 0;
	pm[++i] = 0;
	pm[++i] = 1 * (proj->sx / 10);
	while (++i < 15)
		pm[i] = 0;
	pm[i] = 1;
}
