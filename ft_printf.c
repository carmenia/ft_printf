#include "ft_printf.h"

void	ft_sort_format(t_arg *a)
{
	if ((CUR == 'u' && a->size[2] != 1 && a->size[3] != 1) ||
			((CUR == 'd' || CUR == 'i') && a->size[5] == 1))
		ft_uint(a);
/*	else if (CUR == 'x')
		ft_xint(a);
	else if (CUR == 'X')
		ft_xmajint(a);
	else if (CUR == 'o' && a->size[3] != 1 && a->size[2] != 1)
		ft_oint(a);
	else if (CUR == 'O' || CUR == 'o')
		ft_omajint(a);
	else if (CUR == 'D' || ((CUR == 'd' || CUR == 'i') &&
				(a->size[2] == 1 || a->size[3] == 1 || a->size[4] == 1)))
		ft_long(a);
	else if (CUR == 's' && a->size[2] != 1)
		ft_str(a);
	else if (CUR == 'i' || CUR == 'd')
		ft_int(a);
	else if (CUR == 'S' || (CUR == 's' && a->size[2] == 1))
		ft_wstr(a);
	else if (CUR == 'c' && a->size[2] != 1)
		ft_char(a);
	else if (CUR == 'U' || (CUR == 'u' && (a->size[2] == 1 || a->size[3] == 1)))
		ft_umajint(a);
	else if (CUR == 'C' || (CUR == 'c' && a->size[2] == 1))
		ft_wchar(a);
	else if (CUR == 'p')
		ft_p(a);*/
	a->cur++;
}


void	ft_start_parsing(t_arg *a)
{
	while (CUR && a->error != 1)
	{
		while (CUR != '%' && CUR != '\0')
		{
			ft_putchar(*a->format);
			a->format++;
			a->len++;
		}
		if (*a->format == '%')
		{
			ft_sort_options(a);
			ft_sort_format(a);
			printf("%s\n,a->format");
		}
		a->var = NULL;
	}
}

void init_s_arg(t_arg *a, const char *format)
{
	a->cur = 0;
	a->len = 0;
	a->error = 0;
	a->format = format;
}

int	ft_printf(const char *format, ...)
{
	t_arg	a;


	init_s_arg(&a, format);
	va_start(a.ap, format);
	ft_start_parsing(&a);
	va_end(a.ap);
	return (a.error == 0 ? a.len : -1);
}
