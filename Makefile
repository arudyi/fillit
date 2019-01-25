#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 17:15:42 by vgrynish          #+#    #+#              #
#    Updated: 2018/11/14 20:34:17 by vgrynish         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

INCL = main.c check_open.c fillit.c ft_strcpy.c ft_strsplit.c solve_gr.c map.c add.c

O = main.o check_open.o fillit.o ft_strcpy.o ft_strsplit.o solve_gr.o map.o add.o

ADD =  -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc $(ADD)  -I. $(INCL)
	gcc -o $(NAME)  $(O)
clean:
	rm -f $(O)
fclean: clean
	rm -f $(NAME)
re:fclean all