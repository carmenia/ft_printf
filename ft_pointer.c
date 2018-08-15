/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:29:40 by vduong            #+#    #+#             */
/*   Updated: 2018/08/15 17:31:04 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_pointer(t_arg *a, int maj)
{
	int		spaces;
	int		size;
	int		i;

	a->var = va_arg(a->ap, void *);
	a->var = ft_addresstostr(a->var, maj);
	size = ft_strlen(a->var);
	spaces = (a->width < size ? 0 : a->width - size);
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
