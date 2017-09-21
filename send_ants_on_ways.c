/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants_on_ways.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:27:45 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/17 16:47:10 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	push_ants(t_lem **lem, t_ants *ants)
{
	t_lem	*tmp;
	int		count;
	t_ants	**ant;
	int		i;

	tmp = *lem;
	count = (int)tmp->ant_count + 1;
	ant = (t_ants**)malloc(sizeof(t_ants) * (count) + 1);
	i = -1;
	while (++i < tmp->ant_count)
		ant[i] = tmp->ants[i];
	ant[i] = ants;
	if (tmp->ant_count)
		free(tmp->ants);
	tmp->ant_count++;
	tmp->ants = ant;
}

static void	push_ants_to_strct(t_lem **lem, int way)
{
	t_ants	*ants;

	ants = (t_ants*)malloc(sizeof(t_ants));
	ants->way = -1;
	if (way > -1)
	{
		(*lem)->go[way]->important++;
		ants->way = way;
	}
	ants->alt_name = 0;
	ants->room = 0;
	ants->action = 0;
	push_ants(lem, ants);
}

static int	get_ant_way(t_lem **lem)
{
	int		i;
	int		j;
	int		tmpi;
	t_lem	*tmp;

	tmp = *lem;
	i = 0;
	j = 0;
	tmpi = -1;
	while (i < tmp->count_go)
	{
		if (!j || tmp->go[i]->important < j)
		{
			j = tmp->go[i]->important;
			tmpi = i;
		}
		i++;
	}
	return (tmpi);
}

int			send_ants(t_lem **lem)
{
	int		i;
	int		way;
	int		count_ant;
	t_lem	*tmp;

	i = 1;
	tmp = *lem;
	count_ant = (int)tmp->ant_count;
	tmp->ant_count = 0;
	while (i <= count_ant)
	{
		way = get_ant_way(lem);
		push_ants_to_strct(lem, way);
		i++;
	}
	return (0);
}
