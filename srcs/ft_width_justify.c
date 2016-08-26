/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_justify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 11:27:30 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/26 12:09:22 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_justify(char *s, va_list args)
{
	int		len;
	int		i;
	int		j;
	char	*arg;

	i = 0;
	j = 0;
	arg = va_arg(args, char*);
	len = (ft_atoi(&s[i++]) * -1) - ft_strlen(arg);
	ft_putstr(arg);
	while (j < len)
	{
		ft_putchar(' ');
		j++;
	}
}
