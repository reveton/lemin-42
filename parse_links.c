/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:29:09 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/20 05:46:43 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	push_links(t_lem **lem, t_links *link)
{
	t_lem	*tmp;
	t_links	**links;
	int		count_r;
	int		i;

	tmp = *lem;
	count_r = tmp->count_links + 1;
	i = 0;
	links = (t_links**)malloc(sizeof(t_links) * count_r);
	while (i < count_r)
	{
		if (i == tmp->count_links)
			links[i] = link;
		else
			links[i] = tmp->links[i];
		i++;
	}
	free(tmp->links);
	tmp->links = links;
}

int			parse_links(char *line, t_lem *lem)
{
	char	**str;
	t_links	*link;

	str = ft_strsplit(line, '-');
	link = (t_links*)malloc(sizeof(t_links));
	link->start = ft_strdup(str[0]);
	link->finish = ft_strdup(str[1]);
	link->start_index = find_room(lem, str[0]);
	link->finish_index = find_room(lem, str[1]);
	push_links(&lem, link);
	free_str(str);
	lem->count_links++;
	return (1);
}
