/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:52:30 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 14:55:34 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# define CUR a->format[a->cur]
# define B ft_atoi(a->var)

void	ft_bint(t_arg *a)
{
	int	zeros;

	a->var = ft_itoabase(va_arg(a->ap, size_t), 2, 0);
	zeros = a->precision - ft_strlen(a->var);
	zeros = (zeros < 0) ? 0 : zeros;
	zeros = (a->dot  && B == 0) ? zeros + 1 : zeros;
	a->width = a->width - (zeros + ft_strlen(a->var));
	a->width = (a->dot && B == 0) ? a->width + 1 : a->width;
	if (a->width > 0 && (!a->flag[ZERO] || PRE > 0) && !a->flag[LESS])
		ft_put_space(a, 2);
	if (a->width > 0 && (a->flag[ZERO] && !a->precision))
		ft_put_space(a, 1);
	if (zeros > 0)
		ft_put_precision(a, zeros);
	if (!(a->dot && B == 0))
		ft_putstr(a->var);
	a->len += ft_strlen(a->var);
	if (a->width > 0 && a->flag[LESS])
		ft_put_space(a, 2);
}


