/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 09:00:38 by student           #+#    #+#             */
/*   Updated: 2020/05/21 09:35:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(char flag)
{
	return (flag == '-' || ft_isdigit(flag) || flag == '.' || flag == '*');
}

int		ft_check_num(unsigned long long number, int size)
{
	int	count;

	count = 0;
	while (number > 0)
	{
		number /= size;
		count++;
	}
	return (count);
}

int		ft_add_width(char c, int width)
{
	int i;

	i = -1;
	while (++i < width)
		ft_putchar_fd(c, 1);
	return (i);
}

int		ft_print_value(char flag, t_lst list_flags, va_list argv)
{
	int count;

	count = 0;
	if (flag == 'c')
		count = ft_print_char(list_flags, argv);
	else if (flag == 's')
		count = ft_print_str(list_flags, argv);
	else if (flag == 'p')
		count = ft_print_ptr(list_flags, argv);
	else if (flag == 'd' || flag == 'i')
		count = ft_print_int(list_flags, argv);
	else if (flag == 'u')
		count = ft_print_unsigned(list_flags, argv);
	else if (flag == 'x')
		count = ft_print_hex("0123456789abcdef", list_flags, argv);
	else if (flag == 'X')
		count = ft_print_hex("0123456789ABCDEF", list_flags, argv);
	else if (flag == '%')
		count = ft_print_precent(list_flags);
	return (count);
}
