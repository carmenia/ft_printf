/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:12:05 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 18:38:34 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_arg *a)
{
	int		spaces;
	int		i;
	char	c;

	c = va_arg(a->ap, int);
	spaces = (a->width < 1 ? 0 : a->width - 1);
	i = 0;
	while (i < spaces && !a->flag[LESS])
	{
		ft_print_single_char(a, ' ');
		i++;
	}
	ft_print_single_char(a, c);
	while (i < spaces && a->flag[LESS])
	{
		ft_print_single_char(a, ' ');
		i++;
	}
}
