/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:06:48 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/26 12:11:54 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precise(char *s, va_list args)
{
	int			i;
	int			len;
	char		*arg;

	i = 0;
	len = ft_atoi(&s[i]);
	arg = va_arg(args, char*);
	while (i < len)
	{
		ft_putchar(arg[i]);
		i++;
	}
}

void		ft_oracle(char c, va_list args)
{
	if (c == 's')
		ft_putstr(va_arg(args, char*));
	else if (c == 'S')
		ft_putstr(va_arg(args, char*));
	else if (c == 'c')
		ft_putchar((char)va_arg(args, int));
	else if (c == 'C')
		ft_putchar(ft_toupper((char)va_arg(args, int)));
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

void		ft_inspect(char *s, va_list args) 
{
	char		c;
	int			i;
	int			d;

	i = 0;
	c = s[i];
	d = ft_atoi(&s[i]);
	if (c == '.')
		ft_precise(&s[i++], args);
	else if (c == '-')
	{
		ft_width_justify(&s[i], args);
	}
	else
		ft_oracle(s[i], args);
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
			ft_inspect(&first[i++], args);
		else if (first[i] != '\0' && first[i] != '%')
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
		printf("%-8sABC\n", av[1]);
		ft_printf("%-8sABC", av[1]);
	}
	return (0);
}
