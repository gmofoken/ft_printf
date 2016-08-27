/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 16:33:38 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/26 16:38:38 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_plus_flag(char *s, va_list args)
{
	int	arg;

	arg = va_arg(args, int);
	if (arg < 0)
		ft_putnbr(arg);
	else
	{
		if (*s == '+')
			ft_putchar('+');
		else
			ft_putchar(' ');
		ft_putnbr(arg);
	}
	return (2);
}

int		ft_flag_zero(char *s, va_list args)
{
	int	arg;
	int	i;

	arg = va_arg(args, int);
	i = 0;
	ft_putendl("#1");
	if (s[i + 1] <= 47 && s[i + 1] >= 58)
	{
		ft_putnbr(arg);
	ft_putendl("#2");
		return (1);
	}
	else
	{
		if (arg < 0)
			ft_putchar('-');
	ft_putendl("#3");
		while (i < ft_atoi(&s[i + 2]))
		{
			ft_putchar('0');
			i++;
		}
		if (arg < 0)
			ft_putnbr(arg * -1);
		else
			ft_putnbr(arg);
	ft_putendl("#4");
	}
	return (2);
}
