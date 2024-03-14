# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:45:17 by jparnahy          #+#    #+#              #
#    Updated: 2024/03/13 20:37:12 by jparnahy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minilib.a

SRCS_PP = ft_printf.c ft_atoi.c
SRCS_SR = ./sources/nbrs.c ./sources/words.c

OBJS_PP = $(SRCS_PP:.c=.o)
OBJS_SR = $(SRCS_SR:.c=.o)

FLAGS = -Wall -Werror -Wextra -c
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS_PP) $(OBJS_SR)
	ar -rc $(NAME) $(OBJS_PP) $(OBJS_SR)

$(OBJS_PP): $(SRCS_PP)
	cc $(FLAGS) $(SRCS_PP)

$(OBJS_SR): $(SRCS_SR)
	cc $(FLAGS) $(SRCS_SR)

clean:
	$(RM) $(OBJS_PP) $(OBJS_SR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
