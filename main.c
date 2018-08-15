#include "ft_printf.h"
#include <stdio.h>
# define TEST "gfd %x  fg", (short)566

int main(void)
{
	printf("[%d]\n", ft_printf(TEST));
	printf("[%d]\n", printf(TEST));
	return (0);
}
