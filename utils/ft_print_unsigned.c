#include "../ft_printf.h"

int		check_add_unsig_width(int size, t_lst list_flags)
{
	int	count;

	count = 0;
	if (list_flags.zero && !list_flags.minus && list_flags.precision <= 0)
		count += ft_add_width('0', list_flags.width - size);
	else if (list_flags.precision >= size)
		count += ft_add_width(' ', list_flags.width - list_flags.precision);
	else
		count += ft_add_width(' ', list_flags.width - size);
	return (count);
}

int		print_unsig_precision(int size, t_lst list_flags)
{
	int	i;

	if (list_flags.precision)
	{
		i = -1;
		while (++i < list_flags.precision - size)
			ft_putchar_fd('0', 1);
		return (i);
	}
	return (0);
}

int		check_minus_unsig(char *str, int size, t_lst list_flags)
{
	int count;

	count = 0;
	if (list_flags.minus)
	{
		count += print_unsig_precision(size, list_flags);
		ft_putstr_fd(str, 1);
		count += size;
		count += check_add_unsig_width(size, list_flags);
	}
	else if (!list_flags.minus)
	{
		count += check_add_unsig_width(size, list_flags);
		count += print_unsig_precision(size, list_flags);
		ft_putstr_fd(str, 1);
		count += size;
	}
	return (count);
}

int		ft_print_unsigned(t_lst list_flags, va_list argv)
{
	char	*str;
	int		size;
	int		count;

	str = ft_utoa(va_arg(argv, unsigned int));
	size = ft_strlen(str);
	count = 0;
	if (list_flags.precision == 0 && str[0] == '0')
	{
		count += ft_add_width(' ', list_flags.width);
		return (count);
	}
	count += check_minus_unsig(str, size, list_flags);
	free(str);
	return (count);
}
