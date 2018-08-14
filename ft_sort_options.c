/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:20:02 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/13 15:34:26 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define A a->format[a->cur]


void	ft_read_flags(t_arg *a)
{
	if (A == '#')
	{
		a->flag[POUND] = 1;
		a->cur++;
	}
	else if (A == '0')
	{
		a->flag[ZERO] = 1;
		a->cur++;
	}
	else if (A == '-')
	{
		a->flag[LESS] = 1;
		a->cur++;
	}
	else if (A == '+')
	{
		a->flag[MORE] = 1;
		a->cur++;
	}
	else if (A == ' ')
	{
		a->flag[SPACE] = 1;
		a->cur++;
	}
}

void	ft_opt_width(t_arg *a)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_isdigit(a->format[i]))
		i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(a->format[a->cur]))
	{
		str[i] = a->format[a->cur];
		a->cur++;
		i++;
	}
	str[i] = '\0';
	a->width = ft_atoi(str);
	free(str);
}

void	ft_opt_size(t_arg *a)
{
	if (a->format[a->cur] == 'h' && a->format[a->cur + 1] == 'h')
	{
		a->size[0] = 1;
		a->cur++;
	}
	else if (a->format[a->cur] == 'h')
		a->size[1] = 1;
	else if (a->format[a->cur] == 'l' && a->format[a->cur + 1] == 'l')
	{
		a->size[3] = 1;
		a->cur++;
	}
	else if (a->format[a->cur] == 'l')
		a->size[2] = 1;
	else if (a->format[a->cur] == 'j')
		a->size[4] = 1;
	else if (a->format[a->cur] == 'z')
		a->size[5] = 1;
	a->cur++;
}


/* si probleme ici, hesite pas a remettre une verif que A = '.'*/
void	ft_opt_precision(t_arg *a)
{
	int	i;
	char	*str;

	a->dot = 1;
	a->cur++;
	if (a->format[a->cur] == '-' || !(ft_isdigit(a->format[a->cur])))
		return ;
	while (ft_isdigit(a->format[i]) && a->format[i] != '\0')
			i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(a->format[a->cur]) && a->format[i] != '\0')
	{
		str[i] = a->format[a->cur];
		a->cur++;
		i++;
	}
	str[i] = '\0';
	a->precision = ft_atoi(str);
	free(str);
}
