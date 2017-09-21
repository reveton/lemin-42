/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:53:49 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/20 06:02:32 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	fill_struct(t_lem **lem)
{
	t_lem *tmp;

	tmp = (t_lem*)malloc(sizeof(t_lem));
	tmp->ant_count = 0;
	tmp->print = 0;
	tmp->last_name = 0;
	tmp->ants = 0;
	tmp->start_act = 0;
	tmp->end_act = 0;
	tmp->rooms = 0;
	tmp->count_rooms = 0;
	tmp->links = 0;
	tmp->count_links = 0;
	tmp->ways = 0;
	tmp->count_ways = 0;
	tmp->good = 0;
	tmp->count_good = 0;
	tmp->go = 0;
	tmp->count_go = 0;
	tmp->map = 0;
	tmp->start_r = 0;
	tmp->finish_r = 0;
	*lem = tmp;
}

int		main(void)
{
	t_lem	*lem;
	t_rooms	*start;
	int		*ar;

	fill_struct(&lem);
	if (!validation(0, lem) || !check_start_end(lem))
		ft_put_error();
	start = get_room(&lem, 1, 0);
	if (start->finish && start->start)
		ft_put_error();
	find_links_with_rooms(&lem, start);
	ar = (int *)malloc(sizeof(int) * (lem->count_rooms));
	find_all_ways(&lem, ar, 0, start);
	if (!lem->count_good)
		ft_put_error();
	find_no_intersceting_ways(&lem);
	send_ants(&lem);
	ft_printf("%s", lem->map);
	ft_printf("\n");
	print_ants_on_screen(&lem, 0);
	return (0);
}
