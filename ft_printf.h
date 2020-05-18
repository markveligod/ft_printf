/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:06:31 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/17 13:06:31 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	int	minus;
	int	zero;
	int	point;
	int	width;
	int	precision;
	int	advance;
}					t_lst;

int		ft_printf(const char *str, ...);
int		ft_check_flag(char flag);
int		ft_add_width(char c, int width);
int		ft_print_value(char flag, t_lst list_flags, va_list argv);
int		ft_check_num(unsigned long long number, int size);
int		ft_print_char(t_lst list_flags, va_list argv);
int		ft_print_str(t_lst list_flags, va_list argv);
int		ft_print_ptr(t_lst list_flags, va_list argv);

#endif