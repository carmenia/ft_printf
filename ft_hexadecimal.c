/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:58:10 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 14:46:24 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define CUR a->format[a->cur]
# define X ft_atoi(a->var)

void	ft_xint(t_arg *a, int maj)
{
	int	zeros;

	a->var = ft_itoabase(va_arg(a->ap, size_t), 8, maj);
	zeros = a->precision - ft_strlen(a->var) - a->flag[POUND];
	zeros = (zeros < 0) ? 0 : zeros;
	zeros = (a->dot  && X == 0) ? zeros + 1 : zeros;
	a->width = a->width - (zeros + ft_strlen(a->var) + a->flag[POUND]);
	a->width = (a->dot && X == 0) ? a->width + 1 : a->width;
	if (a->width > 0 && (!a->flag[ZERO] || PRE > 0) && !a->flag[LESS])
		ft_put_space(a, 2);
	if (a->width > 0 && (a->flag[ZERO] && !a->precision))
		ft_put_space(a, 1);
	if (zeros > 0)
		ft_put_precision(a, zeros);
	if (a->flag[POUND])
		ft_print_two_char(a, '0', maj);
	if (!(a->dot && X == 0))
		ft_putstr(a->var);
	a->len += ft_strlen(a->var);
	if (a->width > 0 && a->flag[LESS])
		ft_put_space(a, 2);
}
