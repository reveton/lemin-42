/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants_on_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:35:33 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 14:01:57 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		update_act(t_lem **lem)
{
	t_lem	*tmp;
	int		i;

	tmp = *lem;
	i = 0;
	while (i < tmp->ant_count)
	{
		if (tmp->ants[i]->action != 3)
			tmp->ants[i]->action = 0;
		i++;
	}
}

static int		check_last_ant(int way, int room, t_lem **lem, t_rooms *end)
{
	int		i;
	t_lem	*tmp;

	i = 0;
	tmp = *lem;
	while (i < tmp->ant_count)
	{
		if (tmp->ants[i]->room == room
				&& !end->finish && tmp->ants[i]->way == way)
			return (0);
		i++;
	}
	return (1);
}

static void		print_one_ant(t_lem **lem, t_ants *ant)
{
	t_lem	*tmp;
	int		way;
	int		j;
	t_rooms	*room;

	tmp = *lem;
	ant->action = 2;
	way = ant->way;
	j = ant->room + 1;
	room = get_room(lem, 3, tmp->go[way]->way[j]);
	if (ant->action == 2 && check_last_ant(way, j, &tmp, room))
	{
		if (room->finish)
			ant->action = 3;
		else
			ant->action = 1;
		if (!ant->alt_name)
		{
			ant->alt_name = tmp->last_name + 1;
			tmp->last_name += 1;
		}
		if (print_ants(lem, ant->alt_name, room->title))
			tmp->print++;
		ant->room = j;
	}
}

static t_ants	*get_right_ant(t_lem **lem, int name)
{
	int		i;
	t_lem	*tmp;

	i = 0;
	tmp = *lem;
	while (i < tmp->ant_count)
	{
		if (tmp->ants[i]->alt_name == name && tmp->ants[i]->action != 2)
			return (tmp->ants[i]);
		i++;
	}
	i = 0;
	while (i < tmp->ant_count)
	{
		if (!tmp->ants[i]->room && tmp->ants[i]->action != 2)
			return (tmp->ants[i]);
		i++;
	}
	return (tmp->ants[name]);
}

void			print_ants_on_screen(t_lem **lem, int i)
{
	t_lem	*tmp;
	int		ants;
	t_ants	*ant;

	tmp = *lem;
	ants = 0;
	while (i < tmp->ant_count)
	{
		ant = get_right_ant(lem, i + 1);
		if (ant->action != 3)
			print_one_ant(&tmp, ant);
		else
			ants++;
		i++;
	}
	update_act(&tmp);
	tmp->print = 0;
	if (ants != tmp->ant_count)
	{
		ft_printf("\n");
		print_ants_on_screen(&tmp, 0);
	}
}
