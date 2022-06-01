# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 10:39:11 by botilia           #+#    #+#              #
#    Updated: 2021/11/27 11:44:46 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

BASE =	ft_printf_char_str.c	ft_work_with_di_u.c\
		ft_work_with_pointer_x.c	fts_libfts.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c,%.o,$(BASE))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	cc $(FLAGS) -c $< -o $@

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re