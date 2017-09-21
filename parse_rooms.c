/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:25:15 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/20 05:45:34 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	push_other_rooms(t_lem **lem, t_rooms *room)
{
	t_lem	*tmp;
	t_rooms	**rooms;
	int		count_r;
	int		i;

	tmp = *lem;
	count_r = tmp->count_rooms + 1;
	i = 0;
	rooms = (t_rooms**)malloc(sizeof(t_rooms) * count_r);
	while (i < count_r)
	{
		if (i == tmp->count_rooms)
			rooms[i] = room;
		else
			rooms[i] = tmp->rooms[i];
		i++;
	}
	free(tmp->rooms);
	tmp->rooms = rooms;
}

int			parse_rooms(char *line, t_lem *lem)
{
	char	**str;
	t_rooms	*room;

	str = ft_strsplit(line, ' ');
	room = (t_rooms*)malloc(sizeof(t_rooms));
	room->title = ft_strdup(str[0]);
	room->start = 0;
	room->finish = 0;
	room->index = lem->count_rooms + 1;
	push_other_rooms(&lem, room);
	if (lem->end_act == 1)
	{
		room->finish = 1;
		lem->end_act = 2;
		lem->finish_r = 1;
	}
	if (lem->start_act == 1)
	{
		room->start = 1;
		lem->start_act = 2;
		lem->start_r = 1;
	}
	free_str(str);
	lem->count_rooms++;
	return (1);
}
