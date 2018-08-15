/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:20:18 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 17:36:20 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>

#include <stdio.h>

# define POUND 0
# define ZERO 1
# define LESS 2
# define MORE 3
# define SPACE 4
# define PRE a->precision
# define CUR a->format[a->cur]

typedef struct		s_arg
{
	va_list		ap;
	const char	*format;
	int			flag[5];
	int			size[6];
	int			cur;
	int			len;
	int			dot;
	char		*var;
/*	int			star;*/
	int			width;
	int			precision;
	int			error;
}					t_arg;
int					ft_printf(const char *format, ...);
void				ft_start_parsing(t_arg *a);
void				ft_sort_options(t_arg *a);
void				ft_sort_format(t_arg *a);
void				ft_uint(t_arg *a);
void				ft_print_percent(t_arg *a);
void				ft_read_flags(t_arg *a);
void				ft_opt_width(t_arg *a);
void				ft_opt_size(t_arg *a);
void				ft_opt_precision(t_arg *a);
void				ft_print_percent(t_arg *a);
void				ft_print_u2(t_arg *a, unsigned long u, int zeros);
int					pf_is_posdigit(char c);
int					pf_strchr(char *s, char c);
void				ft_put_space(t_arg *a, int flag);
void				ft_put_precision(t_arg *a, int zeros);
void				ft_dint(t_arg *a);
void				ft_print_single_char(t_arg *a, char c);
char				*ft_itoabase(long long n, int b, int maj);
void				ft_oint(t_arg *a);
void				ft_xint(t_arg *a, int maj);
char				*ft_addresstostr(void *address, int maj);
void				ft_print_two_char(t_arg *a, char c, int maj);
void				ft_bint(t_arg *a);
void				ft_str(t_arg *a);
void				ft_pointer(t_arg *a);

/*test*/
void				ft_printargs(t_arg a);

#endif
