#include "printf.h"

void	ft_print_percent(t_arg *a)
{
	ft_putchar('%');
	a->len++;
	a->cur++;
}

void	ft_put_space(t_arg *a, int flag)
{
	while (a->width != 0)
	{
		if (flag == 1)
			ft_putchar('0');
		if (flag == 2)
			ft_putchar(' ');
		a->len++;
		a->width--;
	}
}
