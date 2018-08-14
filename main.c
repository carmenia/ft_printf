#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("[%d]\n", printf("a%ua", 654));
	printf("{%d}\n", ft_printf("a%ua", 654));
	return (0);
}
