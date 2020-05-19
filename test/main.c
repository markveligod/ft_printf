#include <stdio.h>
#include "../ft_printf.h"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KORG  "\x1B[33m"
#define RESET "\033[0m"

void    print_test(char *name_test)
{
    printf(KORG"\n==============TESTING-%s==============\n"RESET, name_test);
    printf("\n");
}

void    test_any_str()
{
    int res_1, res_2;
    print_test(" any str");
    //TEST # 1
    res_1 = ft_printf("ft_printf: OLO1234567890 \n");
    res_2 = printf("printf: OLO1234567890 \n");
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

}

void    test_c()
{
    int res_1, res_2;
    print_test(" %c");
    //TEST # 1
    res_1 = ft_printf("ft_printf: %c \n", 'O');
    res_2 = printf("printf: %c \n", 'K');
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);
}

void    test_s()
{
    int res_1, res_2;
    print_test(" %s");
    //TEST # 1
    res_1 = ft_printf("ft_printf: %s \n", "HELLO");
    res_2 = printf("printf: %s \n", "HELLO");
    printf("\nResult ft_printf: %d(%d)\nResult printf: %d\n\n", res_1, res_1 - 3, res_2);

    //TEST # 2
    res_1 = ft_printf("%-9s: %2s \n", "ft_printf", "HELLO");
    res_2 = printf("%-9s: %2s \n", "printf", "HELLO");
    printf("\nResult ft_printf: %d\nResult printf: %d\n\n", res_1, res_2);

    //TEST # 3
    char *str = NULL;
    res_1 = ft_printf("%20s: %2s \n", str, "HELLO");
    res_2 = printf("%20s: %2s \n", str, "HELLO");
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);
}

void    test_p()
{
    int res_1, res_2;
    print_test(" %p");
    //TEST # 1
	char *str = NULL;
    res_1 = ft_printf("ft_printf: %p \n", str);
    res_2 = printf("printf: %p \n", str);
    printf("\nResult ft_printf: %d(%d)\nResult printf: %d\n\n", res_1, res_1 - 3, res_2);

	//test # 2
	str = "";
	res_1 = ft_printf("ft_printf: %p \n", str);
    res_2 = printf("printf: %p \n", str);
    printf("\nResult ft_printf: %d(%d)\nResult printf: %d\n\n", res_1, res_1 - 3, res_2);

	//test # 3
	str = "STR";
	res_1 = ft_printf("%s %20p \n", "printf:", str);
    res_2 = printf("%s %20p \n", "printf:", str);
    printf("\nResult ft_printf: %d\nResult printf: %d\n\n", res_1, res_2);

    //TEST # 4
	str = NULL;
    res_1 = ft_printf("%s %15p \n", "printf:", str);
    res_2 = printf("%s %15p \n", "printf:", str);
    printf("\nResult ft_printf: %d\nResult printf: %d\n\n", res_1, res_2);
}

int main(void)
{
    test_any_str();
    test_c();
    test_s();
	test_p();
}
