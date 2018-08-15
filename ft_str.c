/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:17:34 by vduong            #+#    #+#             */
/*   Updated: 2018/08/15 16:31:17 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str(t_arg *a)
{
	int	size;
	int	spaces;
	int	i;

	a->var = va_arg(a->ap, char *);
	size = strlen(a->var);
	size = (a->dot && a->precision < size ? a->precision : size);
	spaces = ((a->width < size ? 0 : a->width - size));
	i = 0;
	while (i < spaces && !a->flag[LESS])
	{
		ft_print_single_char(a, ' ');
		i++;
	}
	i = 0;
	while (i < size)
		ft_print_single_char(a, a->var[i++]);
	i = 0;
	while (i < spaces && a->flag[LESS])
	{
		ft_print_single_char(a, ' ');
		i++;
	}
}
