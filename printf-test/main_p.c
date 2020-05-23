#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "../ft_printf.h"

void error(int c1, int c2)
{
	if (c1 != c2)
		printf("__________________!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!____________________\nprintf_%d | ft_printf_%d\n\n\n\n", c1, c2);
}

int main()
{
	int c1;
	int c2;
	
	printf("\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_ADDRESS\n\n");
	char a;
	char *ptr;
	a = 0;
	printf("\n\nTest with NULL:\n");
	c1 = printf("|%p|%5p|%10p|%.p|\n", NULL, NULL, NULL, NULL);
	c2 = ft_printf("|%p|%5p|%10p|%.p|\n", NULL, NULL, NULL, NULL);
	error(c1, c2);

	printf("\n\nTest with 0:\n");
	c1 = printf("|%p|%5p|%10p|%.p|\n", 0, 0, 0, 0);
	c2 = ft_printf("|%p|%5p|%10p|%.p|\n", 0, 0, 0, 0);
	error(c1, c2);

	printf("\n\nTest with 2:\n");
	c1 = printf("|%p|%5p|%10p|%.p|\n", 12, 12, 12, 12);
	c2 = ft_printf("|%p|%5p|%10p|%.p|\n", 12, 12, 12, 12);
	error(c1, c2);

	printf("\n\nNormal tests without warnings:\n");
	c1 = printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", &a, &a, &a, &a, &a, &a);
	c2 = ft_printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", &a, &a, &a, &a, &a, &a);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	c2 = ft_printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%.p|%p|%3p|%5p|\n", NULL, NULL, NULL, NULL);
	c2 = ft_printf("|%.p|%p|%3p|%5p|\n", NULL, NULL, NULL, NULL);
	error(c1, c2);

	printf("\n\nUndefined behavior tests:\n");
	c1 = printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", &a, &a, &a, &a, &a, &a);
	c2 = ft_printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", &a, &a, &a, &a, &a, &a);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	c2 = ft_printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%.p|%.3p|%.5p|%5.10p|\n", NULL, NULL, NULL, NULL);
	c2 = ft_printf("|%.p|%.3p|%.5p|%5.10p|\n", NULL, NULL, NULL, NULL);
	error(c1, c2);
}