/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:34 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 00:20:21 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define P p->precision
#define U p->buf

void	ft_uint(t_printf *p)
{
	int	zeros;

	if (p->txt == 1)
		ft_print_buf(p);
	p->buf = ft_itoabase_u(va_arg(p->ap, size_t), "0123456789");
	zeros = p->precision - ft_strlen(p->buf);
	zeros = (zeros < 0) ? 0 : zeros;
	p->size = p->size - (zeros + ft_strlen(p->buf));
	if (p->size > 0 && (p->flag[ZERO] != 1 || P > 0) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	if (p->size > 0 && (p->flag[ZERO] == 1 && p->precision == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && P == 0 && *(char *)U == '0'))
		ft_print_buf(p);
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}
