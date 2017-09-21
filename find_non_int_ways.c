/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_non_int_ways.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:11:44 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/17 16:45:29 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	push_this_fucking_way(t_lem **lem, t_ways *way)
{
	t_lem	*tmp;
	int		count;
	t_ways	**go;
	int		i;

	tmp = *lem;
	count = tmp->count_go + 1;
	go = (t_ways**)malloc(sizeof(t_ways) * count);
	way->important = way->length;
	i = -1;
	while (++i < tmp->count_go)
		go[i] = tmp->go[i];
	go[i] = way;
	tmp->count_go++;
	free(tmp->go);
	tmp->go = go;
}

static int	check_room_in_arr(t_lem **lem, int index)
{
	int		i;
	int		j;
	int		test;
	t_lem	*tmp;

	i = 0;
	tmp = *lem;
	while (i < tmp->count_go)
	{
		j = 1;
		while (j < (tmp->go[i]->length - 1))
		{
			test = tmp->go[i]->way[j];
			if (index == test)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_intersceting(t_lem **lem, int index)
{
	int		i;
	int		test;
	t_lem	*tmp;

	i = 1;
	tmp = *lem;
	while (i < (tmp->good[index]->length - 1))
	{
		test = tmp->good[index]->way[i];
		if (check_room_in_arr(lem, test))
			return (1);
		i++;
	}
	return (0);
}

static void	check_intersceting_way(t_lem **lem)
{
	int		i;
	int		fuck;
	t_lem	*tmp;

	i = 0;
	tmp = *lem;
	while (i < tmp->count_good)
	{
		if (!check_intersceting(lem, i))
		{
			fuck = i;
			push_this_fucking_way(lem, tmp->good[fuck]);
		}
		i++;
	}
}

void		find_no_intersceting_ways(t_lem **lem)
{
	int		i;
	int		tmpi;
	int		j;
	t_lem	*tmp;

	tmp = *lem;
	i = 0;
	j = 0;
	tmpi = 0;
	while (i < tmp->count_good)
	{
		if (!j || tmp->good[i]->length < j)
		{
			tmpi = i;
			j = tmp->good[i]->length;
		}
		i++;
	}
	push_this_fucking_way(lem, tmp->good[tmpi]);
	check_intersceting_way(lem);
}
