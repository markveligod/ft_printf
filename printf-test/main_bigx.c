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
	printf("\nTEST_HEX\n\n");
	//printf("\n\n\n\n______________________TEST_HEX___________________________________\n\n\n");

	printf("Test min max\n");
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 2147483647, 2147483647, 2147483647, 2147483647);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 2147483647, 2147483647, 2147483647, 2147483647);
	error(c1, c2);
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", -2147483648, -2147483648, -2147483648, -2147483648);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", -2147483648, -2147483648, -2147483648, -2147483648);
	error(c1, c2);
	printf("\n");

	printf("Test larger min max\n");
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	error(c1, c2);
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	error(c1, c2);
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	error(c1, c2);
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	error(c1, c2);
	c1 = printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	c2 = ft_printf("|%%X|%%15X|%%-15X|%%015X|                |%X|%15X|%-15X|%015X|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	error(c1, c2);
	printf("\n");

	printf("\nNormal tests\n");
	c1 = printf("%%X_%%0X_%%3X_%%5X_%%10X|                    |%X|%0X|%3X|%5X|%10X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%X_%%0X_%%3X_%%5X_%%10X|                   *|%X|%0X|%3X|%5X|%10X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%X_%%0X_%%3X_%%5X_%%10X|                    |%X|%0X|%3X|%5X|%10X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%X_%%0X_%%3X_%%5X_%%10X|                   *|%X|%0X|%3X|%5X|%10X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%X_%%0X_%%3X_%%5X_%%10X|                    |%X|%0X|%3X|%5X|%10X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%X_%%0X_%%3X_%%5X_%%10X|                   *|%X|%0X|%3X|%5X|%10X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-X_%%-0X_%%-3X_%%-5X_%%-10X|               |%-X|%-0X|%-3X|%-5X|%-10X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-X_%%-0X_%%-3X_%%-5X_%%-10X|              *|%-X|%-0X|%-3X|%-5X|%-10X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-X_%%-0X_%%-3X_%%-5X_%%-10X|               |%-X|%-0X|%-3X|%-5X|%-10X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-X_%%-0X_%%-3X_%%-5X_%%-10X|              *|%-X|%-0X|%-3X|%-5X|%-10X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-X_%%-0X_%%-3X_%%-5X_%%-10X|               |%-X|%-0X|%-3X|%-5X|%-10X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-X_%%-0X_%%-3X_%%-5X_%%-10X|              *|%-X|%-0X|%-3X|%-5X|%-10X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02X_%%03X_%%05X_%%07X_%%010X|              |%02X|%03X|%05X|%07X|%010X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02X_%%03X_%%05X_%%07X_%%010X|             *|%02X|%03X|%05X|%07X|%010X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02X_%%03X_%%05X_%%07X_%%010X|              |%02X|%03X|%05X|%07X|%010X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02X_%%03X_%%05X_%%07X_%%010X|             *|%02X|%03X|%05X|%07X|%010X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02X_%%03X_%%05X_%%07X_%%010X|              |%02X|%03X|%05X|%07X|%010X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02X_%%03X_%%05X_%%07X_%%010X|             *|%02X|%03X|%05X|%07X|%010X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|          |%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|         *|%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|          |%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.0X_%%0.0X_%%3.0X_%%5.0X_%%10.0X|         *|%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%X.0_%%0.0X_%%3.0X_%%5.0X_%%10.0X|          |%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%X.0_%%0.0X_%%3.0X_%%5.0X_%%10.0X|         *|%.0X|%0.0X|%3.0X|%5.0X|%10.0X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|     |%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|    *|%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|     |%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|    *|%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|     |%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.0X_%%-0.0X_%%-3.0X_%%-5.0X_%%-10.0X|    *|%-.0X|%-0.0X|%-3.0X|%-5.0X|%-10.0X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.0X_%%03.0X_%%05.0X_%%07.0X_%%010.0X|    |%02.0X|%03.0X|%05.0X|%07.0X|%010.0X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.0X_%%03.0X_%%05.0X_%%07.0X_%%010.0X|   *|%02.0X|%03.0X|%05.0X|%07.0X|%010.0X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.0X_%%03.0X_%%05.0X_%%07.0X_%%010.0X|    |%02.0X|%03.0X|%05.0X|%07.0X|%010.0X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.0X_%%03.0X_%%05.0X_%%07.0X_%%010.0X|   *|%02.0X|%03.0X|%05.0X|%07.0X|%010.0X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.0X_%%03.0X_%%05.0X_%%07.0X_%%010.0X|    |%02.0X|%03.0X|%05.0X|%07.0X|%010.0X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.0X_%%03.0X_%%05.0X_%%07.0X_%%010.0X|   *|%02.0X|%03.0X|%05.0X|%07.0X|%010.0X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.3X_%%0.3X_%%3.3X_%%5.3X_%%10.3X|          |%.3X|%0.3X|%3.3X|%5.3X|%10.3X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.3X_%%0.3X_%%3.3X_%%5.3X_%%10.3X|         *|%.3X|%0.3X|%3.3X|%5.3X|%10.3X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.3X_%%0.3X_%%3.3X_%%5.3X_%%10.3X|          |%.3X|%0.3X|%3.3X|%5.3X|%10.3X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.3X_%%0.3X_%%3.3X_%%5.3X_%%10.3X|         *|%.3X|%0.3X|%3.3X|%5.3X|%10.3X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.3X_%%0.3X_%%3.3X_%%5.3X_%%10.4X|          |%.3X|%0.3X|%3.3X|%5.3X|%10.4X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.3X_%%0.3X_%%3.3X_%%5.3X_%%10.4X|         *|%.3X|%0.3X|%3.3X|%5.3X|%10.4X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.2X_%%-0.2X_%%-3.2X_%%-5.2X_%%-10.2X|     |%-.2X|%-0.2X|%-3.2X|%-5.2X|%-10.2X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.2X_%%-0.2X_%%-3.2X_%%-5.2X_%%-10.2X|    *|%-.2X|%-0.2X|%-3.2X|%-5.2X|%-10.2X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.2X_%%-0.2X_%%-3.2X_%%-5.2X_%%-10.2X|     |%-.2X|%-0.2X|%-3.2X|%-5.2X|%-10.2X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.2X_%%-0.2X_%%-3.2X_%%-5.2X_%%-10.2X|    *|%-.2X|%-0.2X|%-3.2X|%-5.2X|%-10.2X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.2X_%%-0.2X_%%-3.2X_%%-5.2X_%%-10.2X|     |%-.2X|%-0.2X|%-3.2X|%-5.2X|%-10.2X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.2X_%%-0.2X_%%-3.2X_%%-5.2X_%%-10.2X|    *|%-.2X|%-0.2X|%-3.2X|%-5.2X|%-10.2X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.2X_%%03.2X_%%05.2X_%%07.2X_%%010.2X|    |%02.2X|%03.2X|%05.2X|%07.2X|%010.2X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.2X_%%03.2X_%%05.2X_%%07.2X_%%010.2X|   *|%02.2X|%03.2X|%05.2X|%07.2X|%010.2X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.2X_%%03.2X_%%05.2X_%%07.2X_%%010.2X|    |%02.2X|%03.2X|%05.2X|%07.2X|%010.2X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.2X_%%03.2X_%%05.2X_%%07.2X_%%010.2X|   *|%02.2X|%03.2X|%05.2X|%07.2X|%010.2X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.2X_%%03.2X_%%05.2X_%%07.2X_%%010.2X|    |%02.2X|%03.2X|%05.2X|%07.2X|%010.2X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.2X_%%03.2X_%%05.2X_%%07.2X_%%010.2X|   *|%02.2X|%03.2X|%05.2X|%07.2X|%010.2X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.5X_%%0.5X_%%3.5X_%%5.5X_%%10.5X|          |%.5X|%0.5X|%3.5X|%5.5X|%10.5X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.5X_%%0.5X_%%3.5X_%%5.5X_%%10.5X|         *|%.5X|%0.5X|%3.5X|%5.5X|%10.5X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.5X_%%0.5X_%%3.5X_%%5.5X_%%10.5X|          |%.5X|%0.5X|%3.5X|%5.5X|%10.5X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.5X_%%0.5X_%%3.5X_%%5.5X_%%10.5X|         *|%.5X|%0.5X|%3.5X|%5.5X|%10.5X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.5X_%%0.5X_%%3.5X_%%5.5X_%%6.5X|           |%.5X|%0.5X|%3.5X|%5.5X|%6.5X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.5X_%%0.5X_%%3.5X_%%5.5X_%%6.5X|          *|%.5X|%0.5X|%3.5X|%5.5X|%6.5X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.5X_%%-0.5X_%%-3.5X_%%-5.5X_%%-10.5X|     |%-.5X|%-0.5X|%-3.5X|%-5.5X|%-10.5X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.5X_%%-0.5X_%%-3.5X_%%-5.5X_%%-10.5X|    *|%-.5X|%-0.5X|%-3.5X|%-5.5X|%-10.5X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.5X_%%-0.5X_%%-3.5X_%%-5.5X_%%-10.5X|     |%-.5X|%-0.5X|%-3.5X|%-5.5X|%-10.5X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.5X_%%-0.5X_%%-3.5X_%%-5.5X_%%-10.5X|    *|%-.5X|%-0.5X|%-3.5X|%-5.5X|%-10.5X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.5X_%%-0.5X_%%-3.5X_%%-5.5X_%%-10.5X|     |%-.5X|%-0.5X|%-3.5X|%-5.5X|%-10.5X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.5X_%%-0.5X_%%-3.5X_%%-5.5X_%%-10.5X|    *|%-.5X|%-0.5X|%-3.5X|%-5.5X|%-10.5X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.5X_%%03.5X_%%05.5X_%%07.5X_%%010.5X|    |%02.5X|%03.5X|%05.5X|%07.5X|%010.5X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.5X_%%03.5X_%%05.5X_%%07.5X_%%010.5X|   *|%02.5X|%03.5X|%05.5X|%07.5X|%010.5X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.5X_%%03.5X_%%05.5X_%%07.5X_%%010.5X|    |%02.5X|%03.5X|%05.5X|%07.5X|%010.5X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.5X_%%03.5X_%%05.5X_%%07.5X_%%010.5X|   *|%02.5X|%03.5X|%05.5X|%07.5X|%010.5X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.5X_%%03.5X_%%05.5X_%%07.5X_%%010.5X|    |%02.5X|%03.5X|%05.5X|%07.5X|%010.5X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.5X_%%03.5X_%%05.5X_%%07.5X_%%010.5X|   *|%02.5X|%03.5X|%05.5X|%07.5X|%010.5X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%X|%X|%X\n", 2, 16, 30);
	c2 = ft_printf("%X|%X|%X\n", 2, 16, 30);
	error(c1, c2);

	printf("\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------\n\n");

	c1 = printf("%%0-8.3X|%%0-8.5X|%%10|                         |%0-8.3X|%0-8.5X|%10|\n", -8473);
	c2 = ft_printf("%%0-8.3X|%%0-8.5X|%%10|                        *|%0-8.3X|%0-8.5X|%10|\n", -8473);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%2-2.5X_%%2-3.5X_%%2-5.5X_%%2-7.5X_%%2-10.5X|    |%2-2.5X|%2-3.5X|%2-5.5X|%2-7.5X|%2-10.5X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%2-2.5X_%%2-3.5X_%%2-5.5X_%%2-7.5X_%%2-10.5X|   *|%2-2.5X|%2-3.5X|%2-5.5X|%2-7.5X|%2-10.5X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%2-2.5X_%%2-3.5X_%%2-5.5X_%%2-7.5X_%%2-10.5X|    |%2-2.5X|%2-3.5X|%2-5.5X|%2-7.5X|%2-10.5X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%2-2.5X_%%2-3.5X_%%2-5.5X_%%2-7.5X_%%2-10.5X|   *|%2-2.5X|%2-3.5X|%2-5.5X|%2-7.5X|%2-10.5X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%2-2.5X_%%2-3.5X_%%2-5.5X_%%2-7.5X_%%2-10.5X|    |%2-2.5X|%2-3.5X|%2-5.5X|%2-7.5X|%2-10.5X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%2-2.5X_%%2-3.5X_%%2-5.5X_%%2-7.5X_%%2-10.5X|   *|%2-2.5X|%2-3.5X|%2-5.5X|%2-7.5X|%2-10.5X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%2.6-8X_%%3.6-8X_%%5.6-8X_%%7.6-8X_%%10X|              |%2.6-8X|%3.6-8X|%5.6-8X|%7.6-8X|%10.6-8X|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%2.6-8X_%%3.6-8X_%%5.6-8X_%%7.6-8X_%%10.6-8X|             *|%2.6-8X|%3.6-8X|%5.6-8X|%7.6-8X|%10.6-8X|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%2.6-8X_%%3.6-8X_%%5.6-8X_%%7.6-8X_%%10.6-8X|              |%2.6-8X|%3.6-8X|%5.6-8X|%7.6-8X|%10.6-8X|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%2.6-8X_%%3.6-8X_%%5.6-8X_%%7.6-8X_%%10.6-8X|             *|%2.6-8X|%3.6-8X|%5.6-8X|%7.6-8X|%10.6-8X|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%2.6-8X_%%3.6-8X_%%5.6-8X_%%7.6-8X_%%10.6-8X|              |%2.6-8X|%3.6-8X|%5.6-8X|%7.6-8X|%10.6-8X|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%2.6-8X_%%3.6-8X_%%5.6-8X_%%7.6-8X_%%10.6-8X|             *|%2.6-8X|%3.6-8X|%5.6-8X|%7.6-8X|%10.6-8X|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");
}