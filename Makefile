# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/23 10:28:43 by gmofoken          #+#    #+#              #
#    Updated: 2016/08/23 10:36:52 by gmofoken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRCS = srcs/ft_printf.c

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

