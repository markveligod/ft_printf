/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:35:37 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/18 20:35:37 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_str(t_lst list_flags, va_list argv)
{
	char	*str;
	int		size;
	int		count;

	count = 0;
	if (!(str = va_arg(argv, char *)))
		str = ft_strdup("(null)");
	size = ft_strlen(str);
	if (!list_flags.minus && list_flags.width > size)
	{
		ft_add_width((list_flags.zero == 1) ? '0' : ' ', list_flags.width - size);
		ft_putstr_fd(str, 1);
		count += list_flags.width;
	}
	else if (list_flags.minus && list_flags.width > size)
	{
		ft_putstr_fd(str, 1);
		ft_add_width((list_flags.zero == 1) ? '0' : ' ', list_flags.width - size);
		count += list_flags.width;
	}
	else
	{
		ft_putstr_fd(str, 1);
		count += size;
	}
	return (count);
}
