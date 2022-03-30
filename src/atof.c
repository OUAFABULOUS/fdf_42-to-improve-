/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:26:11 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/21 17:29:54 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_handle_sign(char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

float	*ft_advanced_atof(char *str)
{
	int				i;
	int				sign;
	unsigned int	res;
	float			*ret;

	i = 0;
	sign = 1;
	res = 0;
	ret = malloc(1 * sizeof(float));
	if (!ret)
		return (NULL);
	ft_handle_sign(str, &i, &sign);
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((res > INT_MAX && sign == 1) || (res > 2147483648 && sign == -1))
	{
		free(ret);
		return (NULL);
	}
	else
		*ret = (float)res * (float)sign;
	return (ret);
}
