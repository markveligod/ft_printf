/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:59:45 by student           #+#    #+#             */
/*   Updated: 2020/05/21 09:49:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_precent(t_lst list_flags)
{
	int count;

	count = 0;
	if (list_flags.minus)
	{
		ft_putchar_fd('%', 1);
		if (list_flags.zero)
			count += ft_add_width('0', list_flags.width - 1);
		else
			count += ft_add_width(' ', list_flags.width - 1);
	}
	else if (!list_flags.minus)
	{
		if (list_flags.zero)
			count += ft_add_width('0', list_flags.width - 1);
		else
			count += ft_add_width(' ', list_flags.width - 1);
		ft_putchar_fd('%', 1);
	}
	return (count + 1);
}
