/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:20:18 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/15 12:48:26 by vduong           ###   ########.fr       */
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
void				ft_star_parsing(t_arg *a);
void				ft_sort_options(t_arg *a);
void				ft_sort_format(t_arg *a);
void				p(t_arg *a);
void				wchar(t_arg *a);
void				dint(t_arg *a);
void				str(t_arg *a);
void				longdint(t_arg *a);
void				wstr(t_arg *a);
void				treat_char(t_arg *a);
void				umajint(t_arg *a);
void				omajint(t_arg *a);
void				oint(t_arg *a);
void				xmajint(t_arg *a);
void				xint(t_arg *a);
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
/*test*/
void				ft_printargs(t_arg a);

#endif
