# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 16:28:59 by mal-ketb          #+#    #+#              #
#    Updated: 2025/04/19 13:26:37 by mal-ketb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstdel.c \
	   ft_lstmap.c ft_lstnew.c ft_lstpop_back.c parsing.c\
	   sorting.c sortingv2.c stack_creation.c ft_lstlast.c operations.c operations2.c operations3.c \
	   compress.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c ft_libft.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
