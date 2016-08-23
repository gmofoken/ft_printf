/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:06:48 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/23 11:25:01 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oracle(char c, va_list args)
{
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	if (c == 'c')
		ft_putchar(va_arg(args, char));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	if (c == 'o')
		ft_putstr(ft_itoa_base(va_arg(args, char *)));
}

void	ft_printf(char *first, ...)
{
	int			i;
	va_list		args;

	i = 0;
	va_start(args, first);
	while (first[i] != '\0')
	{
		while (first[i] != '\0' && first[i] != '%')
		{
			ft_putchar(first[i]);
			i++;
		}
		if (first[i++] == '%')
			ft_oracle(first[i], args);
		i++;
	}
	va_end(args);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_putendl("");
	else
	{
		printf("Hello KG%s\n", av[1]);
		ft_printf("Hello KG%s", av[1]);
	}
	return (0);
}
