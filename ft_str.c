/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:17:34 by vduong            #+#    #+#             */
/*   Updated: 2018/08/15 15:07:25 by vduong           ###   ########.fr       */
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
	size = (size > a->precision ? a->precision : size);
	spaces = (a->width < size ? 0 : a->width - size);
	i = 0;
	while (spaces > i++)
		ft_print_single_char(a, ' ');
	i = 0;
	while (size > i++)
		ft_print_single_char(a, a->var[i]);
}
