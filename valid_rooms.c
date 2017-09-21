/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:52:12 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 19:54:17 by afomenko         ###   ########.fr       */
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
		if (line[0] == 'L')
			return (0);
		i++;
	}
	return (1);
}

static	int		check_coord(char *line)
{
	int				i;
	long long int	coords;

	i = 0;
	coords = ft_atoi(line);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) || coords >= 2147483648)
			return (0);
		i++;
	}
	return (1);
}

int				check_room_coord(char *line)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
	{
		if (i == 0)
		{
			if (!check_room(str[i]))
				return (0);
		}
		else
		{
			if (!check_coord(str[i]))
				return (0);
		}
		i++;
	}
	if (i == 3)
	{
		free_str(str);
		return (1);
	}
	return (0);
}

static int		bad_room_min(t_lem **lem, int index)
{
	int		i;
	int		start;
	int		finish;
	int		err;
	t_lem	*tmp;

	tmp = *lem;
	i = 0;
	err = 0;
	while (i < tmp->count_links)
	{
		start = tmp->links[i]->start_index;
		finish = tmp->links[i]->finish_index;
		if (start == index)
			err++;
		if (finish == index)
			err++;
		i++;
	}
	if (!err)
		return (0);
	return (1);
}

int				bad_rooms(t_lem **lem)
{
	int		i;
	t_lem	*tmp;

	i = 0;
	tmp = *lem;
	while (i < tmp->count_rooms)
	{
		if (!bad_room_min(lem, (*lem)->rooms[i]->index))
			return (0);
		i++;
	}
	return (1);
}
