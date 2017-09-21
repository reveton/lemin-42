/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rooms_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:03:06 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 13:57:58 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_spaces(const char *line)
{
	int	i;
	int	count_space;

	i = 0;
	count_space = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count_space++;
		i++;
	}
	if (count_space == 2)
		return (1);
	return (0);
}
