/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:19:48 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/19 11:19:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_minus_int(char *str, int num, int size, t_lst list_flags)
{
	int count;

	count = 0;
	if (num < 0)
		*str++;
	if (list_flags.minus)
	{
		if (num < 0 && list_flags.precision < size && !list_flags.zero)
		{
			ft_putchar_fd('-', 1);
			count += 1;
		}
		else if (list_flags.precision > 0)
		{
			if (num < 0)
			{
				ft_putchar_fd('-', 1);
				count += 1;
			}
		}
	}
}

int     ft_print_int(t_lst list_flags, va_list argv)
{
	char	*str;
	int		size;
	int		count;
	int		num;

	num = va_arg(argv, int);
	str = ft_itoa(num);
	size = ft_strlen(str);
	count = 0;
	if (list_flags.zero && (list_flags.minus || list_flags.precision >= 0))
		list_flags.zero = 0;
	if (list_flags.precision == 0 && str[0] == '0')
	{
		count += ft_add_width(' ', list_flags.width);
		return (count);
	}
	count += check_minus_int(str, num, size, list_flags);
	free(str);
	return (count);
}