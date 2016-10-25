/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 16:33:38 by gmofoken          #+#    #+#             */
/*   Updated: 2016/10/25 17:47:11 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_plus_flag(char *s, va_list args)
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

int				ft_places(int value)
{
	int		num;

	num = value;
	if (num < 0)
		num *= -1;
	else if (num < 10)
		return (1);
	else if (num < 100)
		return (2);
	else if (num < 1000)
		return (3);
	else if (num < 10000)
		return (4);
	else if (num < 100000)
		return (6);
	else if (num < 1000000)
		return (7);
	else if (num < 10000000)
		return (8);
	else if (num < 100000000)
		return (9);
	else if (num < 1000000000)
		return (10);
	return (0);
}

static void		ft_zero_f(int arg, int j, int i)
{
	if (arg < 0)
	{
		ft_putchar('-');
		j -= ft_places(arg) + 2;
	}
	while (i < j)
	{
		ft_putchar('0');
		i++;
	}
	if (arg < 0)
		ft_putnbr(arg * -1);
	else
		ft_putnbr(arg);
}

int				ft_flag_zero(char *s, va_list args)
{
	int		arg;
	int		i;
	int		j;

	arg = va_arg(args, int);
	i = 0;
	j = ft_atoi(s) - ft_places(arg);
	if (s[i + 1] <= 47 && s[i + 1] >= 58)
	{
		ft_putnbr(arg);
		return (1);
	}
	else
		ft_zero_f(arg, j, i);
	return (2);
}
