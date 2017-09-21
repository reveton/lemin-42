/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_links_with_rooms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:32:00 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/20 05:45:54 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	push_link_to_strct(t_lem **lem, int *ar, t_rooms *room)
{
	t_lem	*tmp;
	t_ways	*way;
	t_ways	**arr;
	int		count;
	int		i;

	tmp = *lem;
	way = (t_ways*)malloc(sizeof(t_ways));
	way->length = count_ar(ar);
	way->way = ar;
	way->prev = room->index;
	count = tmp->count_ways + 1;
	i = 0;
	arr = (t_ways**)malloc(sizeof(t_ways) * count);
	while (i < count)
	{
		if (i == tmp->count_ways)
			arr[i] = way;
		else
			arr[i] = tmp->ways[i];
		i++;
	}
	free(tmp->ways);
	tmp->ways = arr;
	return (1);
}

static int	*add_to_arr(int *ar, int link)
{
	int i;
	int count;
	int *tmp;

	i = -1;
	count = count_ar(ar);
	if (!count)
		return (create_arr(ar, link));
	tmp = (int*)malloc(sizeof(int) * (count + 2));
	while (ar[++i])
		tmp[i] = ar[i];
	tmp[i] = link;
	tmp[i + 1] = 0;
	free(ar);
	return (tmp);
}

static int	*find_link(t_lem **lem, int room, int *ar)
{
	int		i;
	t_lem	*tmp;

	i = 0;
	tmp = *lem;
	while (i < tmp->count_links)
	{
		if (tmp->links[i]->start_index == room)
			ar = add_to_arr(ar, tmp->links[i]->finish_index);
		else if (tmp->links[i]->finish_index == room)
			ar = add_to_arr(ar, tmp->links[i]->start_index);
		i++;
	}
	return (ar);
}

int			find_links_with_rooms(t_lem **lem, t_rooms *start)
{
	t_lem	*tmp;
	int		*ar;
	int		i;
	t_rooms	*r;

	i = 0;
	ar = 0;
	tmp = *lem;
	ar = find_link(&tmp, start->index, ar);
	if (push_link_to_strct(&tmp, ar, start))
		tmp->count_ways++;
	while (ar[i])
	{
		r = get_room(&tmp, 3, ar[i]);
		if (!r->finish && !check_in_ar(tmp, r))
			find_links_with_rooms(lem, r);
		i++;
	}
	return (0);
}
