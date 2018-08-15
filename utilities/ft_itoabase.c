/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:42:08 by vduong            #+#    #+#             */
/*   Updated: 2018/08/15 12:50:47 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_sizenumber(long long number, int base)
{
	int	size;

	size = 1;
	while (number / base > 0)
	{
		number /= base;
		size++;
	}
	return (size);
}

char	*ft_itoabase(long long n, int b, int maj)
{
	int		n_size;
	char	*itoa;
	int		rest;
	char	*basetable;
	int		is_negative;

	is_negative = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	basetable = (!maj ? "0123456789abcdef" : "0123456789ABCDEF");
	n_size = ft_sizenumber(n, b) + is_negative;
	if (!(itoa = (char *)malloc(sizeof(char) * n_size + 1)))
		return (NULL);
	if (is_negative)
		itoa[0] = '-';
	itoa[n_size--] = 0;
	while (n_size >= 0 + is_negative)
	{
		rest = n % b;
		itoa[n_size--] = basetable[rest];
		n /= b;
	}
	return (itoa);
}
