#include "printf.h"
#include <stdio.h>

int main(void)
{
	printf("[%d]\n", ft_printf("%5u", 654));
	return (0);
}
