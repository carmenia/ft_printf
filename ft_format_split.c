/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:11:59 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/16 22:55:01 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_else_spec_flag(int spec_flag, int *start_ptr, int i)
{
	if (spec_flag == 1)
		*start_ptr = i;
	return (0);
}

void	ft_init_format_split(t_split *sp_sct)
{
	sp_sct->i = 0;
	sp_sct->spec_flag = 1;
	sp_sct->start = 0;
	sp_sct->first = ft_lst_init();
	sp_sct->info_struct = ft_info_init();
}

t_lst	*ft_format_split(char *format)
{
	t_split	sp_sct;

	ft_init_format_split(&sp_sct);//initialise sp_sct, i = 0, flag = 1, start = 0
	while (format[sp_sct.i] != 0)// parcourt tout le format
	{
		if (ft_conv(format, sp_sct.i, 0, &(sp_sct.info_struct)) >= 1)//avance if != '%'
		{
			if (sp_sct.spec_flag == 0)
				ft_add_str_lst(format, sp_sct.i, sp_sct.start, sp_sct.first);
			sp_sct.spec_flag = 1;
			sp_sct.spec_size = ft_add_spec_lst(sp_sct.first,
					&(sp_sct.info_struct));
			sp_sct.i = sp_sct.i + sp_sct.spec_size;
		}
		else
		{
			sp_sct.spec_flag = ft_else_spec_flag(sp_sct.spec_flag,
					&(sp_sct.start), sp_sct.i);
		}
		(sp_sct.i)++;
	}
	if (sp_sct.spec_flag == 0)
		ft_add_str_lst(format, sp_sct.i, sp_sct.start, sp_sct.first);
	ft_empty_struct(&(sp_sct.info_struct));
	return (sp_sct.first);
}
