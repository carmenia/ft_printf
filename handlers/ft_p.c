/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:09 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 12:13:19 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define U p->buf
#define S p->size

void	ft_p(t_printf *p)
{
	if (p->txt == 1)
		ft_print_buf(p);
	p->buf = ft_itoabase_u(va_arg(p->ap, size_t), "0123456789abcdef");
	p->size = p->size - ft_strlen(p->buf) - 2;
	if (S > 0 && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_putchar('0');
	if (p->format[p->idx2] == 'X')
		ft_putchar('X');
	else
		ft_putchar('x');
	p->len += 2;
	if (!(p->dot == 1 && U == 0))
		ft_print_buf(p);
	if (S > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}
