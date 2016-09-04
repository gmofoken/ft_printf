/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:06:48 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/04 13:39:48 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precise(char *s, va_list args)
{
	size_t			i;
	size_t			len;
	char		*arg;

	i = 0;
	len = ft_atoi(&s[i]);
	arg = va_arg(args, char*);
	while (i < len && i < ft_strlen(arg))
	{
		ft_putchar(arg[i]);
		i++;
	}
	return (3);
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

int		ft_inspect(char *s, va_list args) 
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (s[i] == '.')
		ret = ft_precise(&s[i++], args);
	else if (s[i] == '+' || s[i] == ' ')
		ret = ft_plus_flag(&s[i], args);
	else if (s[i] == '-')
		ret = ft_width_justify(&s[i], args);
	else if (s[i] == '0')
		ret = ft_flag_zero(&s[i], args);
	else if (s[i] == '#')
		ret = ft_pound(&s[i + 1], args);
	else
		ft_oracle(s[i], args);
	return (ret);
}


void	ft_printf(char *first, ...)
{
	int			i;
	va_list		args;

	i = 0;
	va_start(args, first);
	while (first[i] != '\0')
	{
		if (first[i] == '%')
		{
			i++;
			i += ft_inspect(&first[i], args);
		}
		else if (first[i] != '\0' && first[i] != '%')
			ft_putchar(first[i]);
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
		printf("%#10x\n", ft_atoi(av[1]));
		ft_printf("%#10x\n", ft_atoi(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
