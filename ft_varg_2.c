/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:14:47 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/16 21:14:48 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_change_type(t_lst *first)
{
	if (first->type == 'i')
		first->type = 'd';
	if (first->type == 'p')
	{
		first->type = 'x';
		first->mdf = ft_safe_free(first->mdf);
		first->ret = 1;
		first->mdf = ft_strdup("l");
		if (first->flags)
			first->flags = ft_str_pos_ins(first->flags, 0, "#");
		else
		{
			first->flags = ft_strnew(1);
			first->flags[0] = '#';
		}
	}
}

void		ft_v_type_clean(t_lst *first)
{
	char	*str;
	int		i;

	i = 0;
	str = "DOUCS";
	while (first)
	{
		i = 0;
		ft_change_type(first);
		while (str[i])
		{
			if (first->type == str[i])
			{
				first->type = str[i] + 'a' - 'A';
				first->mdf = ft_safe_free(first->mdf);
				first->mdf = ft_strnew(1);
				first->mdf[0] = 'l';
			}
			i++;
		}
		if (first->type)
			first->v_type = ft_v_type(first->type, first->mdf);
		first = first->next;
	}
}
