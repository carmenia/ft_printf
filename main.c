#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("[%d]\n", ft_printf("%u", 5));
/*	printf("[%d]\n", printf("%%"));*/
	return (0);
}
