/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:09:01 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/07 14:21:33 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count_elem(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	***ft_ultimate_split(char **tab)
{
	int		i;
	int		len;
	char	***ret;

	i = 0;
	len = ft_count_elem(tab);
	ret = malloc((len + 1) * sizeof(char **));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = ft_split(tab[i], " ");
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	ft_check_lines(char ***d_tab, int i, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		if (ft_count_elem(d_tab[k]) != i)
			return (0);
		k++;
	}
	return (1);
}

float	**ft_float_tab(char ***d_tab, int n_lines, int n_elem)
{
	int		i;
	int		j;
	float	**ret;
	float	*atof;

	i = 0;
	ret = malloc(n_lines * sizeof(float *));
	if (!ret)
		return (NULL);
	while (i < n_lines)
	{
		ret[i] = malloc(n_elem * sizeof(float));
		j = 0;
		while (j < n_elem)
		{
			atof = ft_advanced_atof(d_tab[i][j]);
			if (!ft_is_digit(d_tab[i][j]) || !atof)
				return (free_uncompleted_tab(&atof, &ret, i));
			ret[i][j] = *atof;
			free(atof);
			j++;
		}
		i++;
	}
	return (ret);
}
