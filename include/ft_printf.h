/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:34:36 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/04 11:03:22 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

void		ft_printf(char *first, ...);
int			ft_width_justify(char *s, va_list args);
void		ft_oracle(char c, va_list args);
int			ft_plus_flag(char *s, va_list args);
int			ft_flag_zero(char *s, va_list args);
int			ft_pound(char *s, va_list args);
int			ft_places(int value);

#endif
