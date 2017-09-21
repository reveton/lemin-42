# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afomenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/11 14:04:52 by afomenko          #+#    #+#              #
#    Updated: 2017/09/11 14:16:50 by afomenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB     = libft/
NAME    = lem-in
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    =	find_all_ways.c parse_links.c valid_ants.c\
			find_links_with_rooms.c parse_rooms.c valid_comments_commands.c\
			find_non_int_ways.c print_ants.c valid_links.c\
			print_ants_on_screen.c valid_other.c ft_joinfree.c\
			send_ants_on_ways.c valid_rooms.c\
			main.c support_func.c valid_rooms_spaces.c\
			support_func_two.c validation.c\

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "libft.a:\n"
	@make -C $(LIB)
	@printf "\x1b[33m[libft.a created]\x1b[0m\n"
	@$(CC) $(SRCS) $(LIB)libft.a -o $(NAME)
	@printf "\x1b[33m[%s created]\x1b[0m\n" $(NAME)

.c.o:
	@printf "\x1b[36m[+]\x1b[0m %s\n" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@printf "\x1b[31mDelete objects:\x1b[0m\n"
	@rm -rf $(OBJS)
	@make -C $(LIB) clean

fclean: clean
	@printf "\x1b[31mDelete %s && libft/libft.a:\x1b[0m\n" $(NAME)
	@rm -rf $(NAME)
	@make -C $(LIB) fclean

re: fclean all

