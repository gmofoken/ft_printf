/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 14:46:46 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/03 16:03:45 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex(int arg, char *s)
{
	int		trav;
	int		i;
	int		j;

	i = 0;
	trav = ft_atoi(s);
	j = 3;
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

	return (2);
}

int		ft_pound(char *s, va_list args)
{
	int		arg;
	int		i;

	i = 0;
	arg = va_arg(args, int);
	if (s[i] == '0')
		ft_hex(arg, s);
	return (4);
}
