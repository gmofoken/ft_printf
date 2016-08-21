/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:06:48 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/21 17:07:18 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(char *first, ...)
{
	int			i;
	va_list		args;

	va_start(args, format)
	while (first[i] != '\0')
	{
		while (first[i] != '\0' && first[i] != '%')
			ft_putchar(first[i]);
		if (arg[i] == '%')
			i += oracle(first, ap)
	}
	va_end;
}
