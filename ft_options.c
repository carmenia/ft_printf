/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:48:19 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/21 15:09:23 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_options(t_printf *p)
{
	int	i;

	i = 0;
	while (i != 5)
	{
		p->flag[i] = 0;
		i++;
	}
	i = 0;
	while (i != 6)
	{
		p->modif[i] = 0;
		i++;
	}
	p->dot = 0;
	p->precision = 0;
	p->size = 0;
}

void		ft_opt_specifier(t_printf *p)
{
	if ((F == '-' || F == '+' ||
				F == '#' || F == '0' ||
				F == ' '))
		ft_opt_flag(p);
	if (ft_isdigit(F) && F != '0')
		ft_opt_size(p);
	if (F == 'h' || F == 'l' ||
			F == 'j' || F == 'z')
		ft_opt_modif(p);
	if (F == '.')
		ft_opt_precision(p);
}

int			ft_is_option(t_printf *p)
{
	if (p->format[p->idx1 + 1] == '%' || F == '\0')
		return (1);
	while ((F == '-' || F == '+' ||
				F == '#' || F == '0' ||
				F == ' ' || F == 'h' ||
				F == 'l' || F == 'j' ||
				F == 'z' || F == '.' ||
				(ft_isdigit(F))) && F != '\0')
		ft_opt_specifier(p);
	return (1);
}