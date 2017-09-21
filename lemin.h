/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:39:51 by afomenko          #+#    #+#             */
/*   Updated: 2017/09/20 05:40:54 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define FD 0
# include <fcntl.h>
# include "libft/libft.h"

typedef enum	e_del
{
	FIRST,
	SECOND,
	BOTH
}				t_del;

typedef struct	s_rooms
{
	char		*title;
	int			index;
	int			start;
	int			finish;
}				t_rooms;

typedef struct	s_links
{
	char		*start;
	char		*finish;
	int			start_index;
	int			finish_index;
}				t_links;

typedef struct	s_ways
{
	int			*way;
	int			important;
	int			length;
	int			prev;
}				t_ways;

typedef struct	s_ants
{
	int			alt_name;
	int			way;
	int			room;
	int			action;
}				t_ants;

typedef struct	s_lem
{
	int			start_r;
	int			finish_r;
	char		*map;
	int			ant_count;
	int			print;
	int			last_name;
	int			count_rooms;
	int			start_act;
	int			end_act;
	int			count_links;
	int			count_ways;
	int			count_good;
	int			count_go;
	t_ants		**ants;
	t_rooms		**rooms;
	t_links		**links;
	t_ways		**ways;
	t_ways		**good;
	t_ways		**go;
}				t_lem;

int				change_chrtoix(t_lem *lem);
char			*ft_joinfree(char *str1, char *str2, t_del string);
void			ft_put_error(void);
void			free_str(char **str);
int				find_room(t_lem *lem, char *room);
int				count_ar(const int *ar);
t_rooms			*get_room(t_lem **lem, int type, int index);
int				*create_arr(int *ar, int link);
int				check_in_ar(t_lem *tmp, t_rooms *room);
int				is_room_in_ar(const int *ar, int room, int index);
int				print_ants(t_lem **lem, int ant, char *room);
void			print_ants_on_screen(t_lem **lem, int i);
int				send_ants(t_lem **lem);
void			find_no_intersceting_ways(t_lem **lem);
int				find_all_ways(t_lem **lem, int *ar, int ix, t_rooms *start);
int				find_links_with_rooms(t_lem **lem, t_rooms *start);
int				parse_links(char *line, t_lem *lem);
int				parse_rooms(char *line, t_lem *lem);
int				line_break(const char *line);
int				empty_struct(t_lem **lem);
int				check_start_end(t_lem *lem);
int				check_ants(char *line, t_lem *lem);
int				check_link_dash(const char *line);
int				check_link(char *line);
int				check_comments(const char *line);
int				check_commands(char *line, t_lem *lem);
int				check_spaces(const char *line);
int				check_room_coord(char *line);
int				bad_rooms(t_lem **lem);
int				validation(char *line, t_lem *lem);
#endif
