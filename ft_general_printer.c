/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:49:59 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 11:43:46 by carmenia         ###   ########.fr       */
/*   Updated: 2018/08/14 17:06:32 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_arg *a)
{
	ft_putchar('%');
	a->len++;
}

void	ft_print_single_char(t_arg *a, char c)
{
	write(1, &c, 1);
	a->len++;
}

void	ft_put_space(t_arg *a, int flag)
{
	while (a->width != 0)
	{
		if (flag == 1)
			ft_putchar('0');
		if (flag == 2)
			ft_putchar(' ');
		a->len++;
		a->width--;
	}
}

void	ft_put_precision(t_arg *a, int zeros)
{
	while (zeros != 0)
	{
		ft_putchar('0');
		a->len++;
		zeros--;
	}
}
