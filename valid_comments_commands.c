/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_comments_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:05:54 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/12 14:39:46 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_comments(const char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int		check_commands(char *line, t_lem *lem)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ("##start", line) &&
				lem->start_act != 2 && lem->start_act != 1)
			lem->start_act = 1;
		else if (ft_strequ("##start", line)
				&& (lem->start_act == 2 || lem->start_act == 1))
			return (0);
		if (ft_strequ("##end", line) && lem->end_act != 2
				&& lem->end_act != 1)
			lem->end_act = 1;
		else if (ft_strequ("##end", line)
				&& (lem->end_act == 2 || lem->end_act == 1))
			return (0);
		return (1);
	}
	return (0);
}
