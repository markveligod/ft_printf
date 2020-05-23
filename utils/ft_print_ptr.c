/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:59:53 by student           #+#    #+#             */
/*   Updated: 2020/05/23 09:18:21 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_convert_pointer(char *array_hex, unsigned long long number)
{
	int		size_hex;
	int		count_num;
	char	*str;

	size_hex = ft_strlen(array_hex);
	count_num = ft_check_num(number, size_hex);
	if (!(str = (char *)malloc(sizeof(char) * (count_num + 1))))
		return (NULL);
	str[count_num] = '\0';
	while (--count_num)
	{
		str[count_num] = array_hex[number % size_hex];
		number /= size_hex;
	}
	if (count_num == 0)
		str[count_num] = array_hex[number % size_hex];
	return (str);
}

int		check_minus_ptr(t_lst list_flags, int size, char *str)
{
	int	count;

	count = 0;
	if (list_flags.minus)
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putstr_fd(str, 1);
		count += ft_add_width(' ', list_flags.width - (size + 2));
	}
	else if (!list_flags.minus)
	{
		count += ft_add_width(' ', list_flags.width - (size + 2));
		count += ft_putstr_fd("0x", 1);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}

int		ft_print_ptr(t_lst list_flags, va_list argv)
{
	char				*str;
	int					size;
	int					count;
	unsigned long long	num;

	num = va_arg(argv, unsigned long long);
	if (!num)
		str = ft_strdup("0");
	else
		str = ft_convert_pointer("0123456789abcdef", num);
	size = ft_strlen(str);
	count = 0;
	count += check_minus_ptr(list_flags, size, str);
	free(str);
	return (count);
}
