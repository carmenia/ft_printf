#include "printf.h"
#include <stdio.h>

int main(void)
{
	printf("[%d]\n", printf("% 20.12ld", 0x11ffaa147));
	printf("{%d}\n", ft_printf("% 20.12ld", 0x11ffaa147));
	return (0);
}
