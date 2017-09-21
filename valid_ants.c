/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:18:40 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/11 15:20:36 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_ants(char *line, t_lem *lem)
{
	int				i;
	long long int	ants;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	ants = ft_atoi(line);
	if (ants > 0)
		lem->ant_count = (int)ants;
	if (ants >= 2147483648)
		return (0);
	return (1);
}
