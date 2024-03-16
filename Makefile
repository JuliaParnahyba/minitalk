# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 19:55:32 by jparnahy          #+#    #+#              #
#    Updated: 2024/03/16 18:55:46 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = server_bonus.c client_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra
RM = rm -f

LIBFT = libft/minilib.a

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: mandatory bonus

mandatory: $(OBJS)
	make -C libft
	cc $(FLAGS) server.o $(LIBFT) -o server
	cc $(FLAGS) client.o $(LIBFT) -o client

bonus: $(OBJS_BONUS)
	make -C libft
	cc $(FLAGS) server_bonus.o $(LIBFT) -o server_bonus
	cc $(FLAGS) client_bonus.o $(LIBFT) -o client_bonus

clean:
	make -C libft clean
	$(RM) $(OBJS) 
	$(RM) $(OBJS_BONUS)

fclean:	clean
	make -C libft fclean
	$(RM) server client
	$(RM) server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re
