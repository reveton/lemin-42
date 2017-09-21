/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:20:54 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 17:54:13 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		line_break(const char *line)
{
	if (!line[0])
		return (1);
	if (line[0] == '\n' && line[1] == '\n')
		return (1);
	if (line[0] == '\n' && line[1] == '\0')
		return (1);
	return (0);
}

int		empty_struct(t_lem **lem)
{
	t_lem	*tmp;

	tmp = *lem;
	if (!tmp->ant_count || !tmp->count_rooms || !tmp->count_links)
		return (1);
	return (0);
}

int		check_start_end(t_lem *lem)
{
	if (lem->start_r != 1 || lem->finish_r != 1)
		return (0);
	return (1);
}

int		change_chrtoix(t_lem *lem)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < lem->count_links)
	{
		tmp = find_room(lem, lem->links[i]->finish);
		if (tmp > -1)
			lem->links[i]->finish_index = tmp;
		if (tmp == -1)
			return (0);
		tmp = find_room(lem, lem->links[i]->start);
		if (tmp > -1)
			lem->links[i]->start_index = tmp;
		if (tmp == -1)
			return (0);
		i++;
	}
	return (1);
}
