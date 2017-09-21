/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:45:39 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 14:01:21 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			count_ar(const int *ar)
{
	int	i;

	if (!ar)
		return (0);
	i = 0;
	while (ar[i])
		i++;
	return (i);
}

t_rooms		*get_room(t_lem **lem, int type, int index)
{
	int		i;

	i = 0;
	while (i < (*lem)->count_rooms)
	{
		if (type == 1 && (*lem)->rooms[i]->start)
			return ((*lem)->rooms[i]);
		else if (type == 2 && (*lem)->rooms[i]->finish)
			return ((*lem)->rooms[i]);
		else if (type == 3 && (*lem)->rooms[i]->index == index)
			return ((*lem)->rooms[i]);
		i++;
	}
	return (0);
}

int			*create_arr(int *ar, int link)
{
	int i;

	ar = (int*)malloc(sizeof(int));
	i = 0;
	while (i < 1)
	{
		ar[i] = link;
		i++;
	}
	ar[i] = '\0';
	return (ar);
}

int			check_in_ar(t_lem *tmp, t_rooms *room)
{
	int		i;

	i = 0;
	while (i < tmp->count_ways)
	{
		if (tmp->ways[i]->prev == room->index)
			return (1);
		i++;
	}
	return (0);
}

int			is_room_in_ar(const int *ar, int room, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (ar[i] == room)
			return (1);
		i++;
	}
	return (0);
}
