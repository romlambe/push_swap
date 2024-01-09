# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 13:06:30 by romlambe          #+#    #+#              #
#    Updated: 2024/01/09 13:40:01 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algo.c convert_to_numbers.c free.c ft_rev_rotate.c ft_rotate.c \
	ft_swap.c main.c push_swap_ft.c set_list.c sort_numbers.c \
	split.c utils.c utils_2.c



CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all : author $(NAME)

author :
	@echo "Author :\tromlambe\n"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : author fclean all

.PHONY: all clean fclean re




