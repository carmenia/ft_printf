/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addresstostr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:48:01 by vduong            #+#    #+#             */
/*   Updated: 2018/08/15 13:48:15 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char	*ft_addresstostr(void *address, int maj)
{
	char	*str;
	int		size;
	int		i;
	char	*pureaddress;

	pureaddress = ft_itoabase((long long)address, 16, maj);
	size = ft_strlen(pureaddress);
	if (!(str = (char*)malloc(sizeof(char) * size + 3)))
		return (NULL);
	str[0] = '0';
	str[1] = (!maj ? 'x' : 'X');
	str[size + 3] = '\0';
	i = 0;
	while (i < size)
	{
		str[i + 2] = pureaddress[i];
		i++;
	}
	return (str);
}
