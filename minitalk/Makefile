# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 17:48:15 by qmoreau           #+#    #+#              #
#    Updated: 2022/04/04 19:14:29 by qmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME1 = server

NAME2 = client

FLAGS = -Wall -Wextra -Werror -g

SRCS1 = server.c

SRCS2 = client.c

OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJS1)
			cd Libft && $(MAKE) bonus
			cp Libft/libft.a .
			$(CC) $(FLAGS) -o $(NAME1) $(OBJS1) libft.a

$(NAME2) : $(OBJS2)
			cd Libft && $(MAKE) bonus
			cp Libft/libft.a .
			$(CC) $(FLAGS) -o $(NAME2) $(OBJS2) libft.a

clean :
		rm -f $(OBJS1) $(NAME1) $(OBJS2) $(NAME2)
		$(MAKE) clean -C ./Libft

fclean : clean
		rm -f libft.a
		$(MAKE) fclean -C ./Libft

re : fclean all

.PHONY : fclean clean re all

