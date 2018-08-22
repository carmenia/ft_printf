/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:36 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 11:46:50 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define P p->precision
#define U p->buf
#define S p->size

void	ft_put0x(t_printf *p)
{
	if (p->flag[POUND] == 1 && *(char *)U != '0')
	{
		ft_putchar('0');
		if (p->format[p->idx2] == 'X')
			ft_putchar('X');
		else
			ft_putchar('x');
		p->len += 2;
	}
}

void	ft_xint(t_printf *p)
{
	int	zeros;

	if (p->txt == 1)
		ft_print_buf(p);
	U = ft_itoabase_u(va_arg(p->ap, size_t), "0123456789ABCDEF");
	zeros = p->precision - ft_strlen(p->buf);
	zeros = (zeros < 0) ? 0 : zeros;
	S -= (p->flag[POUND] == 1 && (*(char *)U != '0')) ? 2 : 0;
	S += (p->dot == 1 && P == 0 && S > 0 && *(char *)U == '0') ? 1 : 0;
	S = S - (zeros + ft_strlen(p->buf));
	S = (p->dot == 1 && *(char *)U == '0' && p->flag[POUND] != 1) ? S + 1 : S;
	if (S > 0 && (p->flag[ZERO] != 1 || p->dot == 1) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_put0x(p);
	if (S > 0 && p->flag[ZERO] == 1 && p->dot != 1 && p->flag[LESS] != 1)
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	F == 'x' ? (p->buf = ft_tolowerstr(p->buf)) : 0;
	if (!(p->dot == 1 && P == 0 && *(char *)U == '0'))
		ft_print_buf(p);
	if (S > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}
