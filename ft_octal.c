/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:42:41 by carmenia          #+#    #+#             */
/*   Opdated: 2018/08/15 13:26:26 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define CUR a->format[a->cur]
# define O ft_atoi(a->var)

void	ft_oint(t_arg *a)
{
	int	zeros;

	a->var = ft_itoabase(va_arg(a->ap, size_t), 8, 0);
	zeros = a->precision - ft_strlen(a->var);
	zeros = (zeros < 0) ? 0 : zeros;
	zeros = (a->dot  && O == 0) ? zeros + 1 : zeros;
	a->width = a->width - (zeros + ft_strlen(a->var));
	a->width = (a->dot && O == 0) ? a->width + 1 : a->width;
	if (a->width > 0 && (!a->flag[ZERO] || PRE > 0) && !a->flag[LESS])
		ft_put_space(a, 2);
	if (a->width > 0 && (a->flag[ZERO] && !a->precision))
		ft_put_space(a, 1);
	if (zeros > 0)
		ft_put_precision(a, zeros);
	if (a->flag[POUND])
		ft_print_single_char(a, '0');
	if (!(a->dot && O == 0))
		ft_putstr(a->var);
	a->len += ft_strlen(a->var);
	if (a->width > 0 && a->flag[LESS])
		ft_put_space(a, 2);
}

