/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:41:46 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/12 12:00:41 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_ants(t_lem **lem, int ant, char *room)
{
	t_lem *tmp;

	tmp = *lem;
	if (tmp->print)
		ft_printf(" ");
	ft_printf("\033[31mL\033[0m");
	ft_printf("\033[31m%d\033[0m", ant);
	ft_printf("\033[0;33m-\033[0;33m");
	ft_printf("\033[32m%s\033[32m", room);
	return (1);
}
