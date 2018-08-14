/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:00:37 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/13 19:37:27 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
# define A a->format[a->cur]
# define U ft_atoi(a->var);


void	ft_uint(t_arg *a)
{
	a->var = ft_itoa(va_arg(a->ap, size_t));intzeros;

	zeros = a->precision - ft_strlen(p->buf);
	zeros = (zeros < 0) ? 0 : zeros;
	zeros = (a->dot == 1 && U == 0) ? zeros + 1 : zeros;
	a->width = a->width - (zeros + ft_strlen(a->var) + a->flag[MORE]);
	a->width = (a->dot == 1 && U ==0) ? a->width + 1 : a->width;
	if (a->flag[SPACE] == 1 && a->flag[MORE] == 0)
		a->width--;
	if (a->width > 0 && (a->flag[ZERO] != 1 || P > 0) && a->flag[LESS] != 1)
		ft_put_space(a, 2);
	if (a->width > 0 && (a->flag[ZERO] == 1 && a->precision == 0))
			ft_put_space(p	, 1);
	if (zeros > 0)
		ft_put_precision(a, zeros);
	if (!(a->dot == 1 && U == 0))
		ft_putstr(a->var);
	if (a->width > 0 && (a->flag[LESS] == 1))
		ft_put_space(p, 2);
}
