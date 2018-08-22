/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:48:56 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 12:27:28 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

# define TEST "%x", (unsigned int)4294967296

int		main(void)
{
	unsigned int	i;
	void			*p;
	wchar_t			*str;
	wchar_t			c;
	wchar_t			*s;

	setlocale(LC_ALL, "");
	i = 0;
	p = &i;
	s = L"S„™ºÚÅÄÄS„";
	str = L"S˛";
	c = L'˛';
	printf("[%d]\n", printf(TEST));
	printf("{%d}\n", ft_printf(TEST));
	return (i);
}
