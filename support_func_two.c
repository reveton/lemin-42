/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:49:48 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 14:00:32 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_put_error(void)
{
	ft_printf("ERROR\n");
	exit(-1);
}

void		free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int			find_room(t_lem *lem, char *room)
{
	int	i;

	i = 0;
	while (i < lem->count_rooms)
	{
		if (ft_strequ(room, lem->rooms[i]->title))
			return (lem->rooms[i]->index);
		i++;
	}
	return (-1);
}
