/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:42:06 by gmofoken          #+#    #+#             */
/*   Updated: 2016/10/25 14:13:30 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_flags_two(int num, char *s)
{
	ft_putstr(s);
	if (*s == 'd' || *s == 'i')
		ft_putnbr(num);
	else if (*s == 'x')
		ft_putstr(ft_strmap_i(ft_itoa_base(num, 16), ft_tolower));
	else if (*s == 'X')
		ft_putstr(ft_itoa_base(num, 16));
	else if (*s == 'o' || *s == 'O')
		ft_putstr(ft_itoa_base(num, 8));
}

int		l_flags(char *s, va_list args)
{
	long long	val;
	long long	num;

	val = va_arg(args, long long);
	if (*s == 'l')
	{
		if (val < -9223372036854775807)
			num = -9223372036854775807;
		else if (val > 9223372036854775807)
			num = 9223372036854775807;
		else
			num = val;
		l_flags_two(num, &s[1]);
		return (2);
	}
	else
	{
		if (val < -2147483647)
			num = -2147483647;
		else if (val > 2147483647)
			num = 2147483647;
		else
			num = val;
		l_flags_two(num, s);
		return	(1);
	}
}



int		ft_flags(char *s, va_list args)
{
	int		ret;

	ret = 0;
	if (*s == 'h')
		ret = ft_h_flags(&s[1], args);
	else if (*s == 'l')
		ret = l_flags(&s[1], args);
	else if (*s == 'z')
	{
	
	}

	return (ret);
}
