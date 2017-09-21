/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:35:37 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/17 16:42:46 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	push_others_ways(t_lem **set, t_ways *way)
{
	t_lem	*tmp;
	t_ways	**arr;
	int		count;
	int		i;

	tmp = *set;
	count = tmp->count_good + 1;
	arr = (t_ways**)malloc(sizeof(t_ways*) * (count + 1));
	i = -1;
	while (++i < tmp->count_good)
		arr[i] = tmp->good[i];
	arr[i] = way;
	tmp->count_good++;
	free(tmp->good);
	tmp->good = arr;
}

int			push_first_way(const int *ar, t_lem **lem, int length)
{
	t_ways	*good_way;
	int		i;

	i = -1;
	good_way = (t_ways *)malloc(sizeof(t_ways));
	good_way->way = (int *)malloc(sizeof(int) * (length) + 1);
	good_way->length = length;
	good_way->important = length;
	while (++i < length)
		good_way->way[i] = ar[i];
	push_others_ways(lem, good_way);
	return (0);
}

static void	find_all_ways_min(t_lem *tmp, t_rooms *start, int ix, int *ar)
{
	t_rooms	*room;
	int		k;
	int		count;
	int		i;

	i = 0;
	k = 0;
	count = tmp->count_ways;
	while (i < count)
	{
		if (start->index == tmp->ways[i]->prev)
		{
			while (k < tmp->ways[i]->length)
			{
				room = get_room(&tmp, 3, tmp->ways[i]->way[k]);
				if (!is_room_in_ar(ar, tmp->ways[i]->way[k], ix + 1))
					find_all_ways(&tmp, ar, ix + 1, room);
				k++;
			}
		}
		i++;
	}
}

int			find_all_ways(t_lem **lem, int *ar, int ix, t_rooms *start)
{
	t_lem *tmp;

	tmp = *lem;
	ar[ix] = start->index;
	if (start->finish)
		return (push_first_way(ar, lem, ix + 1));
	find_all_ways_min(tmp, start, ix, ar);
	return (0);
}
