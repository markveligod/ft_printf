/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:59:53 by student           #+#    #+#             */
/*   Updated: 2020/05/21 10:20:50 by student          ###   ########.fr       */
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
	str[count_num] = array_hex[number % size_hex];
	return (str);
}

int		ft_print_with_minus(char *str, int size, int count, t_lst list_flags)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	count += (size + 2);
	if (list_flags.width > 1)
	{
		ft_add_width(' ', list_flags.width - (size + 2));
		count += list_flags.width - (size + 2);
	}
	return (count);
}

int		ft_print_without_minus(char *str, int size, int count, t_lst list_flags)
{
	if (list_flags.width > 1)
	{
		ft_add_width(' ', list_flags.width - (size + 2));
		count += list_flags.width - (size + 2);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	count += size + 2;
	return (count);
}

int		ft_print_ptr(t_lst list_flags, va_list argv)
{
	unsigned long long	number;
	char				*str;
	int					size;
	int					count;

	if (!(number = va_arg(argv, unsigned long long)))
		str = ft_strdup("0");
	else
		str = ft_convert_pointer("0123456789abcdef", number);
	count = 0;
	size = ft_strlen(str);
	if (list_flags.minus)
		count += ft_print_with_minus(str, size, count, list_flags);
	else if (!list_flags.minus)
		count += ft_print_without_minus(str, size, count, list_flags);
	free(str);
	return (count);
}
