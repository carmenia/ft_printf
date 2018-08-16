/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:10:21 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/16 19:11:07 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_percent(t_printf *p)
{
	if (p->txt == 1)
		ft_buf(p);
	p->size--;
	if (p->size > 0 && p->flag[ZERO] == 1 && p->flag[LESS] != 1)
		ft_put_space(p, 1);
	if (p->size > 0 && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_putchar('%');
	p->len++;
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}
