/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:59:39 by student           #+#    #+#             */
/*   Updated: 2020/05/21 11:34:12 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_add_int_width(int num, int size, t_lst list_flags)
{
	int	count;

	count = 0;
	if (list_flags.zero)
	{
		if (list_flags.width > 0 && num < 0)
			count += (ft_add_width('0', list_flags.width - size) - 1);
		else
			count += ft_add_width('0', list_flags.width - size);
	}
	else if (list_flags.precision >= size)
	{
		if (num < 0)
			count += (ft_add_width(' ', list_flags.width -
						list_flags.precision - 1) - 1);
		else
			count += ft_add_width(' ', list_flags.width - list_flags.precision);
	}
	else if (list_flags.width > 0 && list_flags.precision < size && num < 0)
		count += (ft_add_width(' ', list_flags.width - size) - 1);
	else
		count += ft_add_width(' ', list_flags.width - size);
	return (count);
}

int		print_int_precision(int num, int size, t_lst list_flags)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (num < 0 && list_flags.precision < size && !list_flags.zero)
	{
		ft_putchar_fd('-', 1);
		return (1);
	}
	if (list_flags.precision > 0)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			i--;
		}
		while (i++ < list_flags.precision - size)
		{
			ft_putchar_fd('0', 1);
			count++;
		}
	}
	return (count);
}

int		check_minus_int(char *str, int num, int size, t_lst list_flags)
{
	int count;

	count = 0;
	if (num < 0)
		str++;
	if (list_flags.minus)
	{
		count += print_int_precision(num, size, list_flags);
		ft_putstr_fd(str, 1);
		count += size;
		count += check_add_int_width(num, size, list_flags);
	}
	else if (!list_flags.minus)
	{
		count += check_add_int_width(num, size, list_flags);
		count += print_int_precision(num, size, list_flags);
		ft_putstr_fd(str, 1);
		count += size;
	}
	return (count);
}

int		ft_print_int(t_lst list_flags, va_list argv)
{
	char	*str;
	int		size;
	int		count;
	int		num;

	num = va_arg(argv, int);
	str = ft_itoa(num);
	size = ft_strlen(str);
	count = 0;
	count += check_minus_int(str, num, size, list_flags);
	free(str);
	return (count);
}
