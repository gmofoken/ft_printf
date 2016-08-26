/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_justify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 11:27:30 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/26 16:23:10 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_justify(char *s, va_list args)
{
	int		len;
	int		i;
	int		j;
	char	*arg;
	int		ret;

	i = 0;
	j = 0;
	ret = 1;
	arg = va_arg(args, char*);
	if (s[i] == '-')
	{
		len = (ft_atoi(&s[i++]) * -1) - ft_strlen(arg);
		ft_putstr(arg);
		ret = 2;
	}
	else
		len = ft_atoi(&s[i]) - ft_strlen(arg);
	while (j++ < len)
		ft_putchar(' ');
	if (s[i - 1] != '-')
		ft_putstr(arg);
	return (ret);
}
