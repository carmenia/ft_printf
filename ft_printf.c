/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:17 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/21 13:06:05 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_p(t_printf *p, const char *format)
{
	p->buf = NULL;
	p->idx1 = 0;
	p->idx2 = 0;
	p->len = 0;
	p->error = 0;
	p->format = format;
}

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_init_p(&p, format);
	va_start(p.ap, format);
	ft_text_parser(&p);
	va_end(p.ap);
	return ((p.error != -1) ? p.len : -1);
}
