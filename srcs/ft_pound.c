/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 14:46:46 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/04 13:40:00 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_zero_lead(int arg, char *s)
{
	int		trav;
	int		i;
	int		j;
	int		pos;
	int		ret;

	i = 0;
	trav = ft_atoi(s);
	j = 3;
	ret = 4;
	pos = ft_places(arg);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == 'X')
	{
		ft_putstr("0X");
		while (j++ != trav)
			ft_putchar('0');
		ft_putstr(ft_itoa_base(arg, 16));
	}
	else if (s[i] == 'x')
	{
		ft_putstr("0x");
		while (j++ != trav)
			ft_putchar('0');
		ft_putstr(ft_itoa_base(arg, 16));
	}
	return (ret);
}

void		ft_octal_space_lead(int	arg, int trav)
{
	int		i;

	i = 0;
	if (arg == 0)
	{
		while (i++ < trav - 1)
			ft_putchar(' ');
		ft_putnbr(0);
	}
	else if (arg > 0)
	{
		while (i++ < trav - (ft_places(arg) + 1))
			ft_putchar(' ');
		ft_putnbr(0);
		ft_putstr(ft_itoa_base(arg, 8));
	}
}

void		ft_hex_space_lead(int arg, int trav, char c)
{
	int		i;
	char	*rep;
	char	*rep2;

	i = 0;
	rep = ft_strjoin("0X", ft_itoa_base(arg, 16));
	rep2 = ft_strmap_i(rep, ft_tolower);
	if (arg == 0)
	{
		while (i++ < trav -1)
			ft_putchar(' ');
		ft_putnbr(0);
	}
	else if (arg > 0)
	{
		while (i++ < trav - (ft_places(arg) + 2))
				ft_putchar(' ');
		if (c == 'x')
			ft_putstr(rep2);
		else
			ft_putstr(rep);
	}
	free(rep);
	free(rep2);
}

int		ft_space_lead(int arg, char *s)
{
	int		trav;
	int		i;

	trav = ft_atoi(s);
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == 'o')
		ft_octal_space_lead(arg, trav);
	if (s[i] == 'x' || s[i] == 'X')
		ft_hex_space_lead(arg, trav, s[i]);
	return(3);
}

int		ft_pound(char *s, va_list args)
{
	int		arg;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	arg = va_arg(args, int);
	if (s[i] == '0')
		ret = ft_hex_zero_lead(arg, s);
	else if (s[i] >= '1' && s[i] <= '9')
		ret = ft_space_lead(arg, s);
	return (ret);
}
