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
    res_1 = ft_printf("printf: OLO1234567890 \n");
    res_2 = printf("printf: OLO1234567890 \n");
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

}

void    test_c()
{
    int res_1, res_2;
    print_test(" %c");
    //TEST # 1
    res_1 = ft_printf("printf: %c \n", 'O');
    res_2 = printf("printf: %c \n", 'K');
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

    //TEST # 2
    res_1 = ft_printf("printf: %20c \n", 'O');
    res_2 = printf("printf: %20c \n", 'K');
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

    //TEST # 3
    res_1 = ft_printf("printf: %-20c \n", 'O');
    res_2 = printf("printf: %-20c \n", 'K');
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

    //TEST # 3
    res_1 = ft_printf("printf: %20c \n", 0);
    res_2 = printf("printf: %20c \n", 0);
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

    //TEST # 4
    str = "egsrgrfw";
    res_1 = ft_printf("%.20s: %20s \n", str, "HELLO");
    res_2 = printf("%.20s: %20s \n", str, "HELLO");
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

    //TEST # 5
    str = "01334243242342423423";
    res_1 = ft_printf("%-10.2s: %20s \n", str, "HELLO");
    res_2 = printf("%-10.2s: %20s \n", str, "HELLO");
    printf("\nResult ft_printf: %d\nResult printf: %d\n", res_1, res_2);

    //TEST # 6
    str = "ALLO";
    res_1 = ft_printf("%0.2s: %2s \n", str, "HELLO");
    printf("\nResult ft_printf: %d\n\n", res_1);
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

void        test_d_i()
{
    print_test(" %d and %i");
    //TEST #1
    int i = 228;
    int res_1, res_2;
    res_1 = ft_printf("Result: %d - %i\n", i, i);
    res_2 = printf("Result: %d - %i\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #2
    i = -4327628;
    res_1 = ft_printf("Result: %12d <=> %21i\n", i, i);
    res_2 = printf("Result: %12d <=> %21i\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #3
    i = 0;
    res_1 = ft_printf("Result: %-12d <=> %-21i\n", i, i);
    res_2 = printf("Result: %-12d <=> %-21i\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #4
    i = -1488;
    res_1 = ft_printf("Result: %-.12d <=> %-.21i\n", i, i);
    res_2 = printf("Result: %-.12d <=> %-.21i\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #5
    i = 33331488;
    res_1 = ft_printf("Result: %.12d <=> %.21i\n", i, i);
    res_2 = printf("Result: %.12d <=> %.21i\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #6
    res_1 = ft_printf("Result: %.12d <=> %.21i\n", 012, 012);
    res_2 = printf("Result: %.12d <=> %.21i\n", 012, 012);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #7
    res_1 = ft_printf("Result: %-.12d <=> %-.21i\n", 0120, 0120);
    res_2 = printf("Result: %-.12d <=> %-.21i\n", 0120, 0120);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #8
    res_1 = ft_printf("Result: %12d <=> %21i\n", 0120, 0120);
    res_2 = printf("Result: %12d <=> %21i\n", 0120, 0120);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #9
    res_1 = ft_printf("Result: %-12d <=> %-21i\n", 0120, 0120);
    res_2 = printf("Result: %-12d <=> %-21i\n", 0120, 0120);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #10
    res_1 = ft_printf("Result: %*d <=> %*i\n", 12, 0x77, 22, 0x77);
    res_2 = printf("Result: %*d <=> %*i\n", 12, 0x77, 22, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #11
    res_1 = ft_printf("Result: %.*d <=> %.*i\n", 12, 0x77, 22, 0x77);
    res_2 = printf("Result: %.*d <=> %.*i\n", 12, 0x77, 22, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #12
    res_1 = ft_printf("Result: %-.*d <=> %-.*i\n", 12, 0x77, 22, 0x77);
    res_2 = printf("Result: %-.*d <=> %-.*i\n", 12, 0x77, 22, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #13
    res_1 = ft_printf("Result: %-.0d <=> %-.0i\n", 0x77, 0x77);
    res_2 = printf("Result: %-.0d <=> %-.0i\n", 0x77, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #14
    res_1 = ft_printf("Result: %-.0d \n", 0x77);
    res_2 = printf("Result: %-.0d \n", 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);
        
    //TEST #15
    res_1 = ft_printf("Result: %-.0i \n", 0x77);
    res_2 = printf("Result: %-.0i \n", 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #16
    res_1 = ft_printf("Result: %-0.6d <=> %-0.6i\n", 0x77, 0x77);
    printf("ft_printf: %d \n\n", res_1);

    //TEST #17
    res_1 = ft_printf("Result: %0.16d <=> %0.16i\n", -119, -119);
    printf("ft_printf: %d \n\n", res_1);
}

void    test_u()
{
     print_test(" %u");
    //TEST #1
    unsigned int i = 228;
    int res_1, res_2;
    res_1 = ft_printf("Result: %u - %u\n", i, i);
    res_2 = printf("Result: %u - %u\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #2
    i = 4327628;
    res_1 = ft_printf("Result: %12u <=> %21u\n", i, i);
    res_2 = printf("Result: %12u <=> %21u\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #3
    i = 0;
    res_1 = ft_printf("Result: %-12u <=> %-21u\n", i, i);
    res_2 = printf("Result: %-12u <=> %-21u\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #4
    i = 1488;
    res_1 = ft_printf("Result: %-.12u <=> %-.21u\n", i, i);
    res_2 = printf("Result: %-.12u <=> %-.21u\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #5
    i = 33331488;
    res_1 = ft_printf("Result: %.12u <=> %.21u\n", i, i);
    res_2 = printf("Result: %.12u <=> %.21u\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #6
    res_1 = ft_printf("Result: %.12u <=> %.21u\n", 012, 012);
    res_2 = printf("Result: %.12u <=> %.21u\n", 012, 012);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #7
    res_1 = ft_printf("Result: %-.12u <=> %-.21u\n", 0120, 0120);
    res_2 = printf("Result: %-.12u <=> %-.21u\n", 0120, 0120);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #8
    res_1 = ft_printf("Result: %12u <=> %21u\n", 0120, 0120);
    res_2 = printf("Result: %12u <=> %21u\n", 0120, 0120);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #9
    res_1 = ft_printf("Result: %-12u <=> %-21u\n", 0120, 0120);
    res_2 = printf("Result: %-12u <=> %-21u\n", 0120, 0120);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #10
    res_1 = ft_printf("Result: %*u <=> %*u\n", 12, 0x77, 22, 0x77);
    res_2 = printf("Result: %*u <=> %*u\n", 12, 0x77, 22, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #11
    res_1 = ft_printf("Result: %.*u <=> %.*u\n", 12, 0x77, 22, 0x77);
    res_2 = printf("Result: %.*u <=> %.*u\n", 12, 0x77, 22, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #12
    res_1 = ft_printf("Result: %-.*u <=> %-.*u\n", 12, 0x77, 22, 0x77);
    res_2 = printf("Result: %-.*u <=> %-.*u\n", 12, 0x77, 22, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #13
    res_1 = ft_printf("Result: %-.0u <=> %-.0u\n", 0x77, 0x77);
    res_2 = printf("Result: %-.0u <=> %-.0u\n", 0x77, 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #14
    res_1 = ft_printf("Result: %-.0u \n", 0x77);
    res_2 = printf("Result: %-.0u \n", 0x77);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #16
    res_1 = ft_printf("Result: %-0.6u <=> %-0.6u\n", 0x77, 0x77);
    printf("ft_printf: %d \n\n", res_1);

    //TEST #17
    res_1 = ft_printf("Result: %0.16u <=> %0.16u\n", -119, -119);
    printf("ft_printf: %d \n\n", res_1);
}

void    test_x_X()
{
    print_test(" %x %X");
    //TEST #1
    unsigned int i = 228;
    int res_1, res_2;
    res_1 = ft_printf("Result: %x - %X\n", i, i);
    res_2 = printf("Result: %x - %X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #2
    i = -22825245;
    res_1 = ft_printf("Result: %15x - %6X\n", i, i);
    res_2 = printf("Result: %15x - %6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #3
    i = 22825245;
    res_1 = ft_printf("Result: %15x - %6X\n", i, i);
    res_2 = printf("Result: %15x - %6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #4
    i = 22825245;
    res_1 = ft_printf("Result: %-15x - %-6X\n", i, i);
    res_2 = printf("Result: %-15x - %-6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #5
    i = 22825245;
    res_1 = ft_printf("Result: %.5x - %.6X\n", i, i);
    res_2 = printf("Result: %.5x - %.6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);
    
    //TEST #6
    i = 22825245;
    res_1 = ft_printf("Result: %-.5x - %-.6X\n", i, i);
    res_2 = printf("Result: %-.5x - %-.6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #7
    i = 0;
    res_1 = ft_printf("Result: %5x - %6X\n", i, i);
    res_2 = printf("Result: %5x - %6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #8
    i = 22825245;
    res_1 = ft_printf("Result: %-10.5x - %-10.6X\n", i, i);
    res_2 = printf("Result: %-10.5x - %-10.6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #9
    i = 124134134;
    res_1 = ft_printf("Result: %10.5x - %10.6X\n", i, i);
    res_2 = printf("Result: %10.5x - %10.6X\n", i, i);
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #10
    i = 124124414;
    res_1 = ft_printf("Result: %0.5x - %0.6X\n", i, i);
    printf("ft_printf: %d \n\n", res_1);

    //TEST #11
    i = 124124414;
    res_1 = ft_printf("Result: %-0.5x - %-0.6X\n", i, i);
    printf("ft_printf: %d \n\n", res_1);
}

void    test_precent()
{
    print_test(" %%");
    //TEST #1
    int res_1, res_2;
    res_1 = ft_printf("Result: %% LMAO\n");
    res_2 = printf("Result: %% LMAO\n");
    printf("ft_printf: %d \nprintf: %d\n\n", res_1, res_2);

    //TEST #2
    res_1 = ft_printf("Result: %20% LMAO\n");
    printf("ft_printf: %d\n\n", res_1);

    //TEST #3
    res_1 = ft_printf("Result: %-20% LMAO\n");
    printf("ft_printf: %d \n\n", res_1);

    //TEST #4
    res_1 = ft_printf("Result: %0.20% LMAO\n");
    printf("ft_printf: %d \n\n", res_1);
}

int main(void)
{
    test_any_str();
    test_c();
    test_s();
	test_p();
    test_d_i();
    test_u();
    test_x_X();
    test_precent();
}
