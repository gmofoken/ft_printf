/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 09:19:43 by gmofoken          #+#    #+#             */
/*   Updated: 2016/10/25 17:37:16 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_flag(int val, char *s)
{
	int		num;

	if (val < -32767)
		num = -32767;
	else if (val > 32767)
		num = 32767;
	else
		num = val;
	if (*s == 'd' || *s == 'i')
		ft_putnbr(num);
	else if (*s == 'x')
		ft_putstr(ft_strmap_i(ft_itoa_base(num, 16), ft_tolower));
	else if (*s == 'X')
		ft_putstr(ft_itoa_base(num, 16));
	else if (*s == 'o' || *s == 'O')
		ft_putstr(ft_itoa_base(num, 8));
}

int		ft_h_flags(char *s, va_list args)
{
	int		val;

	if (*s == 'h')
	{
		ft_putstr(va_arg(args, char*));
		return (2);
	}
	else
	{
		val = va_arg(args, int);
		h_flag(val, &s[1]);
		return (1);
	}
}
