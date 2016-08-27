# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/23 10:28:43 by gmofoken          #+#    #+#              #
#    Updated: 2016/08/26 11:44:56 by gmofoken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRCS = srcs/ft_printf.c srcs/ft_width_justify.c srcs/ft_plus_flag.c

HEADER = -I include

LFLAGS = -L./libft/ -lft

FLAGS = -o ft_printf -Wall -Werror -Wextra

all:
	@make -C libft/
	@gcc $(FLAGS) $(SRCS) $(HEADER) $(LFLAGS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re: fclean all

