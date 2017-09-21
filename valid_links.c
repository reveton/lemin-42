/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:10:12 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 19:57:09 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		check_room(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isalpha(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_link_dash(const char *line)
{
	int i;
	int dash;

	i = 0;
	dash = 0;
	while (line[i])
	{
		if (line[i] == '-')
			dash++;
		i++;
	}
	if (dash == 1)
		return (1);
	return (0);
}

int				check_link(char *line)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(line, '-');
	while (str[i])
	{
		if (!check_room(str[i]))
			return (0);
		i++;
	}
	if (i == 2)
	{
		free_str(str);
		return (1);
	}
	return (0);
}
