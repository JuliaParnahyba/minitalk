# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 19:55:32 by jparnahy          #+#    #+#              #
#    Updated: 2024/03/18 18:24:53 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRCS = server.c client.c
BONUS_SRCS = server_bonus.c client_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: $(NAME)

libft/minilib.a:
	make -C libft

server: server.o
	cc -Wall -Wextra -Werror -o server server.o libft/minilib.a

client: client.o
	cc -Wall -Wextra -Werror -o client client.o libft/minilib.a

server_bonus: server_bonus.o
	cc -Wall -Wextra -Werror -o server_bonus server_bonus.o libft/minilib.a

client_bonus: client_bonus.o
	cc -Wall -Wextra -Werror -o client_bonus client_bonus.o libft/minilib.a

$(NAME): $(OBJS) libft/minilib.a server client

bonus: $(BONUS_OBJS) libft/minilib.a server_bonus client_bonus

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME) $(OBJS) $(BONUS_OBJS) server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re
