/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:06:48 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/24 14:41:19 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oracle(char c, va_list args)
{
	if (c == 's')
		ft_putstr(va_arg(args, char*));
	else if (c == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'o')
		ft_putstr(ft_itoa_base(va_arg(args, int), 8));
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'u')
		ft_putstr(ft_itoa_base(va_arg(args, int), 10));
	else if (c == 'x')
		ft_putstr(ft_strmap_i(ft_itoa_base(va_arg(args, int), 16), ft_tolower));
	else if (c == 'X')
		ft_putstr(ft_itoa_base(va_arg(args, int), 16));
	else if (c == 'p')
	{
		ft_putstr("0x7fff");
		ft_putstr(ft_strmap_i(ft_itoa_base(va_arg(args, int), 16), ft_tolower));
	}	
}

void	ft_printf(char *first, ...)
{
	int			i;
	va_list		args;

	i = 0;
	va_start(args, first);
	while (first[i] != '\0')
	{
		if (first[i++] == '%')
			ft_oracle(first[i++], args);
		if (first[i] != '\0' && first[i] != '%')
			ft_putchar(first[i++]);
	}
	va_end(args);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_putendl("");
	else
	{
		printf("%.7o\n", 56);
		printf("%c %s\n", (char)av[1], av[2]);
		ft_printf("%c %s\n", av[1], av[2]);
	}
	return (0);
}
