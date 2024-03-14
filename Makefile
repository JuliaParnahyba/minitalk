# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 19:55:32 by jparnahy          #+#    #+#              #
#    Updated: 2024/03/13 21:12:37 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

FLAGS = -Wall -Werror -Wextra -c
RM = rm -f

LIBFT = libft/minilib.a

$(NAME): $(LIBFT) $(NAME_SERVER) $(NAME_CLENT)
	ar -rc $(NAME)

$(NAME_SERVER) $(NAME_CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
	ar -rc $(NAME_SERVER) $(NAME_CLIENT)

$(OBJS_SERVER) $(OBJS_CLIENT): $(SRC_SERVER) $(SRC_CLIENT) $(LIBFT)
	cc $(FLAG) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)
	cc $(FLAG) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:
	clean
	$(RM) $(NAME)

re: fclean all
