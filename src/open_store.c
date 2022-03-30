/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:20:50 by omoudni           #+#    #+#             */
/*   Updated: 2022/02/21 14:20:41 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_char_count(char *str)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1))
		count++;
	close(fd);
	return (count);
}

char	*ft_open_store(char *str)
{
	int		fd;
	int		char_count;
	char	*f_content;
	int		i;
	char	c;

	i = 0;
	fd = open (str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	char_count = ft_char_count(str);
	f_content = malloc(char_count + 1);
	if (!f_content)
		return (NULL);
	while (read(fd, &c, 1) > 0)
	{
		f_content[i] = c;
		i++;
	}
	f_content[i] = '\0';
	return (f_content);
}
