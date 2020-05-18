/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:46:13 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/18 20:46:13 by ckakuna          ###   ########.fr       */
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

int		ft_print_ptr(t_lst list_flags, va_list argv)
{
    char				*str;
    int					size;
	int					count;
	unsigned long long	number;

	if (!(number = va_arg(argv, unsigned long long)))
		str = ft_strdup("(nil)");
	else
		str = ft_convert_pointer("0123456789abcdef", number);
	count = 0;
	size = ft_strlen(str);
	if (list_flags.minus)
	{
		if ((ft_strncmp(str, "(nill)", size - 1)) != 0)
			ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		ft_add_width(' ', list_flags.width - (size + 2));
	}
	else
	{
		ft_add_width(' ', list_flags.width - (size + 2));
		if ((ft_strncmp(str, "(nill)", size - 1)) != 0)
			ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
	}
	count += (list_flags.width > 1) ? list_flags.width : size;
	count += (ft_strncmp(str, "(nill)", size - 1) == 0) ? 0 : 2;
	free(str);
	return(count);
}