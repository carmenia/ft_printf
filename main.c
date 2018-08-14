#include "ft_printf.h"
#include <stdio.h>
# define TEST "%+27.23d", (short int)566

int main(void)
{
	printf("[%d]\n", ft_printf(TEST));
	printf("[%d]\n", printf(TEST));
	return (0);
}
