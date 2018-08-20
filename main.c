/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:34:11 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/20 20:43:43 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

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
	printf("[%d]\n", printf("% 20.12ld", 0x11ffaa147));
	printf("{%d}\n", ft_printf("% 20.12ld", 0x11ffaa147));
	return (i);
}
