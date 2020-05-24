#include "../ft_printf.h"

int		check_width_int(t_lst list_flags, int size, int num)
{
	int	count;

	count = 0;
	if (list_flags.zero)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count++;
		}
		count += ft_add_width('0', list_flags.width - size);
	}
	else if (list_flags.precision >= size)
	{
		if (num < 0)
			count += ft_add_width(' ', list_flags.width -
					list_flags.precision - 1);
		else
			count += ft_add_width(' ', list_flags.width - list_flags.precision);
	}
	else
		count += ft_add_width(' ', list_flags.width - size);
	return (count);
}

int		check_precision_int(t_lst list_flags, int size, int num)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (num < 0 && list_flags.precision < size && !list_flags.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (list_flags.precision > 0)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count++;
			i--;
		}
		while (i++ < list_flags.precision - size)
		{
			write(1, "0", 1);
			count++;
		}
	}
	return (count);
}

int		check_minus_int(t_lst list_flags, int size, char *str, int num)
{
	int	count;

	count = 0;
	if (num < 0)
		str++;
	if (list_flags.minus)
	{
		count += check_precision_int(list_flags, size, num);
		count += ft_putstr_fd(str, 1);
		count += check_width_int(list_flags, size, num);
	}
	else if (!list_flags.minus)
	{
		count += check_width_int(list_flags, size, num);
		count += check_precision_int(list_flags, size, num);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}

int		ft_print_int(t_lst list_flags, va_list argv)
{
	int		num;
	char	*str;
	int		size;
	int		count;

	num = va_arg(argv, int);
	str = ft_itoa(num);
	size = ft_strlen(str);
	count = 0;
	if (list_flags.zero && (list_flags.minus || list_flags.precision >= 0))
		list_flags.zero = 0;
	if (list_flags.precision == 0 && *str == '0')
	{
		count += ft_add_width(' ', list_flags.width);
		return (count);
	}
	count += check_minus_int(list_flags, size, str, num);
	free(str);
	return (count);
}
