/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:00:37 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 14:57:16 by carmenia         ###   ########.fr       */
/*   Updated: 2018/08/14 17:05:55 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define CUR a->format[a->cur]
# define U ft_atoi(a->var)

void	ft_uint(t_arg *a)
{
	int	zeros;

	a->var = ft_itoa(va_arg(a->ap, size_t));
	zeros = a->precision - ft_strlen(a->var);
	zeros = (zeros < 0) ? 0 : zeros;
	zeros = (a->dot  && U == 0) ? zeros + 1 : zeros;
	a->width = a->width - (zeros + ft_strlen(a->var));
	a->width = (a->dot && U == 0) ? a->width + 1 : a->width;
	if (a->width > 0 && (!a->flag[ZERO] || PRE > 0) && !a->flag[LESS])
		ft_put_space(a, 2);
	if (a->width > 0 && (a->flag[ZERO] && !a->precision))
		ft_put_space(a, 1);
	if (zeros > 0)
		ft_put_precision(a, zeros);
	if (!(a->dot && U == 0))
		ft_putstr(a->var);
	a->len += ft_strlen(a->var);
	if (a->width > 0 && a->flag[LESS])
		ft_put_space(a, 2);
}


