#include "ft_printf.h"
#include <stdio.h>

void	ft_printargs(t_arg arg)
{
	printf("----arg----\n");
	printf("format = %s\n", arg.format);
	int i;
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("FLAG[%d] = %d\n", i, arg.flag[i]);
	}
	printf("\n");
	for (i = 0; i < 6; i++)
	{
		printf("SIZE[%d] = %d\n", i, arg.size[i]);
	}
	printf("\n");
	printf("cur = %d\n", arg.cur);
	printf("len = %d\n", arg.len);
	printf("dot = %d\n", arg.dot);
	printf("var = %s\n", arg.var);
	printf("width = %d\n", arg.width);
	printf("precision = %d\n", arg.precision);
	printf("error = %d\n", arg.error);
}
