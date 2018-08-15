/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:06:42 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 14:55:47 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_format(t_arg *a)
{
	if ((CUR == 'u' && a->size[2] != 1 && a->size[3] != 1) ||
			((CUR == 'd' || CUR == 'i') && a->size[5] == 1))
		ft_uint(a);
	else if (pf_strchr("xX", CUR))
		CUR == 'X' ? ft_xint(a, 1) : ft_xint(a, 0);
	else if (pf_strchr("oO", CUR))
		ft_oint(a);
	else if (pf_strchr("bB", CUR))
		ft_bint(a);
	/*	else if (CUR == 's' && a->size[2] != 1)
		ft_str(a);
		*/	
	else if (CUR == 'i' || CUR == 'd'|| CUR == 'D')
		ft_dint(a);/*
				  else if (CUR == 'S' || (CUR == 's' && a->size[2] == 1))
				  ft_wstr(a);
				  else if (CUR == 'c' && a->size[2] != 1)
				  ft_char(a);
				  else if (CUR == 'C' || (CUR == 'c' && a->size[2] == 1))
				  ft_wchar(a);
				  else if (CUR == 'p')
				  ft_p(a);*/
	a->cur++;
}


void	ft_start_parsing(t_arg *a)
{
	while (CUR && a->error != 1)
	{
		a->var = NULL;
		while (CUR != '%' && CUR != '\0')
		{
			ft_putchar(CUR);
			a->cur++;
			a->len++;
		}
		if (CUR == '%')
		{
			a->cur++;
			ft_sort_options(a);
			ft_sort_format(a);
		}
	}
}

void init_s_arg(t_arg *a, const char *format)
{
	int	i;

	i = 0;
	a->cur = 0;
	a->len = 0;
	a->error = 0;
	a->dot = 0;
	a->width = 0;
	a->precision = 0;
	a->format = format;
	while (a->flag[i])
	{
		a->flag[i] = 0;
		i++;
	}
	i = 0;
	while (a->size[i])
	{
		a->size[i] = 0;
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_arg	a;


	init_s_arg(&a, format);
	va_start(a.ap, format);
	ft_start_parsing(&a);
	va_end(a.ap);
	return (a.error == 0 ? a.len : -1);
}
