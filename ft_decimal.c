/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 21:12:48 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/14 21:20:08 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define CUR a->format[a->cur]
# define D ft_atoi(a->var)

void	ft_dint(t_arg *a)
{
	int	zeros;

	a->var = ft_itoa(va_arg(a->ap, size_t));
	zeros = a->precision - ft_strlen(a->var);
	zeros = (zeros < 0) ? 0 : zeros;
	zeros = (a->dot  && D == 0) ? zeros + 1 : zeros;
	a->width = a->width - (zeros + ft_strlen(a->var) + a->flag[MORE]);
	ft_printargs(*a);
	/* a->width = (a->dot && U == 0) ? a->width + 1 : a->width; */
	if (a->flag[SPACE] && !a->flag[MORE])
		a->width--;
	if (a->width > 0 && (!a->flag[ZERO] || PRE > 0) && !a->flag[LESS])
		ft_put_space(a, 2);
	if (a->width > 0 && (a->flag[ZERO] && !a->precision))
		ft_put_space(a, 1);
	if (zeros > 0)
		ft_put_precision(a, zeros);
	if (!(a->dot && D == 0))
		ft_putstr(a->var);
	a->len += ft_strlen(a->var);
	if (a->width > 0 && a->flag[LESS])
		ft_put_space(a, 2);
}
