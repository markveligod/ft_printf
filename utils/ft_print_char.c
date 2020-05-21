/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 09:00:29 by student           #+#    #+#             */
/*   Updated: 2020/05/21 09:09:42 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_char(t_lst list_flags, va_list argv)
{
	if (list_flags.minus == 1 && list_flags.width > 1)
	{
		ft_putchar_fd(va_arg(argv, int), 1);
		ft_add_width(' ', list_flags.width - 1);
		return (list_flags.width);
	}
	else if (list_flags.minus == 0 && list_flags.width > 1)
		ft_add_width(' ', list_flags.width - 1);
	ft_putchar_fd(va_arg(argv, int), 1);
	if (list_flags.width > 1)
		return (list_flags.width);
	return (1);
}
