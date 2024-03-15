# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 19:55:32 by jparnahy          #+#    #+#              #
#    Updated: 2024/03/14 21:16:59 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=server.c client.c
OBJS = $(SRCS:.c=.o)

FLAGS=-Wall -Werror -Wextra
RM=rm -f

LIBFT=libft/minilib.a

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

mandatory: $(OBJS)
	make -C libft
	cc $(FLAGS) server.o $(LIBFT) -o server
	cc $(FLAGS) client.o $(LIBFT) -o client

all: mandatory 

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean:	clean
	make -C libft fclean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re
