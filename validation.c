/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:33:20 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 17:21:31 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		validation(char *line, t_lem *lem)
{
	char	*map;

	map = ft_strdup("");
	while (get_next_line(FD, &line) && line)
	{
		map = ft_joinfree(map, ft_strjoin(line, "\n"), BOTH);
		lem->map = map;
		if (!lem->ant_count && check_ants(line, lem))
			;
		else if (check_commands(line, lem) || check_comments(line))
			;
		else if (check_spaces(line) && check_room_coord(line))
			parse_rooms(line, lem);
		else if (check_link(line) && check_link_dash(line))
			parse_links(line, lem);
		else if (line_break(line))
			break ;
		else
			return (0);
		if (line[0] != '\n' && line[1] != '\n')
			free(line);
	}
	if (!change_chrtoix(lem) || !bad_rooms(&lem) || empty_struct(&lem))
		return (0);
	return (1);
}
