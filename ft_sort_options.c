/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:20:02 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/14 17:35:35 by carmenia         ###   ########.fr       */
/*   Updated: 2018/08/14 17:05:41 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read_flags(t_arg *a)
{
	if (CUR == '#')
	{
		a->flag[POUND] = 1;
		a->cur++;
	}
	else if (CUR == '0')
	{
		a->flag[ZERO] = 1;
		a->cur++;
	}
	else if (CUR == '-')
	{
		a->flag[LESS] = 1;
		a->cur++;
	}
	else if (CUR == '+')
	{
		a->flag[MORE] = 1;
		a->cur++;
	}
	else if (CUR == ' ')
	{
		a->flag[SPACE] = 1;
		a->cur++;
	}
}

void	ft_opt_size(t_arg *a)
{
	if (CUR == 'h' && a->format[a->cur + 1] == 'h')
	{
		a->size[0] = 1;
		a->cur++;
	}
	else if (CUR == 'h')
		a->size[1] = 1;
	else if (CUR == 'l' && a->format[a->cur + 1] == 'l')
	{
		a->size[3] = 1;
		a->cur++;
	}
	else if (CUR == 'l')
		a->size[2] = 1;
	else if (CUR == 'j')
		a->size[4] = 1;
	else if (CUR == 'z')
		a->size[5] = 1;
	a->cur++;
}

void	ft_opt_width_precision(t_arg *a)
{
	int		i;
	char	*str;

	if(CUR == '.')
	{
		a->dot = 1;
		a->cur++;
	}
	i = 0;
	if (!(ft_isdigit(CUR)))
		return ;
	while (ft_isdigit(a->format[i]) && a->format[i] != '\0')
		i++;
	if(!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(CUR) && a->format[i] != '\0')
	{
		str[i] = CUR;
		a->cur++;
		i++;
	}
	a->dot == 1 ? (a->precision = ft_atoi(str)) : (a->width = ft_atoi(str));
	free(str);
}

void	ft_sort_options(t_arg *a)
{
	if (a->format[a->cur] == '%')
	{
		ft_print_percent(a);
		return ;
	}
	while (pf_strchr("-+#0 hljz.", CUR) || pf_is_posdigit(CUR))
	{
		if (pf_strchr("-+#0 ", CUR))
			ft_read_flags(a);
		if (pf_is_posdigit(CUR) || CUR == '.')
			ft_opt_width_precision(a);
		if (pf_strchr("hjlz", CUR))
			ft_opt_size(a);
	}
}
