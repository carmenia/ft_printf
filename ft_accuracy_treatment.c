/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_treatment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:10:51 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/16 21:11:08 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_accuracy_str_treatment_nb(char *str, char *acc, char type)
{
	int		i;
	int		acc_nb;
	char	*added_str;

	added_str = 0;
	acc_nb = ft_atoi(acc + 1);
	if (!(type == 'c' || type == 'C' || type == 's'))
	{
		(str[0] == '-') ? acc_nb++ : acc_nb;
		if ((int)ft_strlen(str) < acc_nb)
		{
			added_str = ft_strnew(acc_nb - (int)ft_strlen(str));
			i = 0;
			while (i < acc_nb - (int)ft_strlen(str))
				added_str[i++] = '0';
			if (str[0] == '-')
				str = ft_str_pos_ins(str, 1, added_str);
			else
				str = ft_str_pos_ins(str, 0, added_str);
		}
		if (acc_nb == 0 && ft_strcmp(str, "0") == 0)
			str[acc_nb] = 0;
	}
	added_str = ft_safe_free(added_str);
	return (str);
}

char	*ft_accuracy_str_treatment(char *str, char *acc, char type, int *r_ptr)
{
	int		i;
	int		acc_nb;

	acc_nb = ft_atoi(acc + 1);
	if ((type == 's' && (int)ft_strlen(str) > acc_nb))
	{
		str[acc_nb] = 0;
		*r_ptr = 0;
	}
	if (!(type == 'c' || type == 'C' || type == 's'))
		str = ft_accuracy_str_treatment_nb(str, acc, type);
	return (str);
}

void	ft_accuracy_treatment(t_lst *first)
{
	while (first)
	{
		if (first->init_str && first->acc != 0 && first->type != '%')
		{
			first->init_str = ft_accuracy_str_treatment(first->init_str,
				first->acc, first->type, &(first->read_bytes));
		}
		first = first->next;
	}
}
