#include "printf.h"
# define A a->format[a->cur]


void	ft_sort_format(t_arg *a)
{
	if ((A == 'u' && a->size[2] != 1 && a->size[3] != 1) ||
			((A == 'd' || A == 'i') && a->size[5] == 1))
		ft_uint(a);
/*	else if (A == 'x')
		ft_xint(a);
	else if (A == 'X')
		ft_xmajint(a);
	else if (A == 'o' && a->size[3] != 1 && a->size[2] != 1)
		ft_oint(a);
	else if (A == 'O' || A == 'o')
		ft_omajint(a);
	else if (A == 'D' || ((A == 'd' || A == 'i') &&
				(a->size[2] == 1 || a->size[3] == 1 || a->size[4] == 1)))
		ft_long(a);
	else if (A == 's' && a->size[2] != 1)
		ft_str(a);
	else if (A == 'i' || A == 'd')
		ft_int(a);
	else if (A == 'S' || (A == 's' && a->size[2] == 1))
		ft_wstr(a);
	else if (A == 'c' && a->size[2] != 1)
		ft_char(a);
	else if (A == 'U' || (A == 'u' && (a->size[2] == 1 || a->size[3] == 1)))
		ft_umajint(a);
	else if (A == 'C' || (A == 'c' && a->size[2] == 1))
		ft_wchar(a);
	else if (A == 'p')
		ft_p(a);*/
	a->cur++;
}

void	ft_sort_options(t_arg *a)
{
	if (a->format[a->cur + 1] == '%' || A == '\0')
	{
		ft_print_percent(a);
		return ;
	}
	while ((A == '-' || A == '+' ||
				A == '#' || A == '0' ||
				A == ' ' || A == 'h' ||
				A == 'l' || A == 'j' ||
				A == 'z' || A == '.' ||
				(ft_isdigit(A))) && A != '\0')
	{
		if ((A == '-' || A == '+' ||
					A == '#' || A == '0' ||
					A == ' '))
			ft_read_flags(a);
		if (ft_isdigit(A) && A != '0')
			ft_opt_size(a);
		if (A == 'h' || A == 'l' ||
				A == 'j' || A == 'z')
			ft_opt_size(a);
		if (A == '.')
			ft_opt_precision(a);
	}
}

void	ft_start_parsing(t_arg *a)
{
	while (a->format[a->cur] && a->error != 1)
	{
		while (a->format[a->cur] != '%' && a->format[a->cur] != '\0')
		{
			ft_putchar(*a->format);
			a->format++;
			a->len++;
		}
		if (*a->format == '%')
		{
			ft_sort_options(a);
			ft_sort_format(a);
		}
		a->var = NULL;
	}
}



int	ft_printf(const char *format, ...)
{
	t_arg	a;

	a.cur = 0;
	a.len = 0;
	a.error = 0;
	a.format = format;

	va_start(a.ap, format);
	ft_start_parsing(&a);
	va_end(a.ap);
	return (a.len = (a.error = 0) ? a.len : -1);
}
