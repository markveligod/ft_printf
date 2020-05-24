#include "ft_printf.h"

t_lst	ft_init(t_lst list_flags)
{
	list_flags.minus = 0;
	list_flags.zero = 0;
	list_flags.point = 0;
	list_flags.width = 0;
	list_flags.precision = -1;
	return (list_flags);
}

t_lst	ft_cut_star(t_lst list_flags, va_list argv)
{
	if (list_flags.point == 1)
		list_flags.precision = va_arg(argv, int);
	else if (list_flags.width < 1)
	{
		list_flags.width = va_arg(argv, int);
		if (list_flags.width < 0)
		{
			list_flags.width *= (-1);
			list_flags.minus = 1;
		}
	}
	return (list_flags);
}

t_lst	ft_cut_flags(const char *flag, t_lst list_flags, va_list argv)
{
	int i;

	i = 0;
	while (flag[i] && ft_check_flag(flag[i]))
	{
		if (flag[i] == '-')
			list_flags.minus = 1;
		else if (flag[i] == '0' && list_flags.width < 1 &&
				list_flags.point == 0)
			list_flags.zero = 1;
		else if (ft_isdigit(flag[i]) && list_flags.point == 0)
			list_flags.width = (list_flags.width * 10) + (flag[i] - 48);
		else if (flag[i] == '.')
		{
			list_flags.point = 1;
			list_flags.precision = 0;
		}
		else if (ft_isdigit(flag[i]) && list_flags.point == 1)
			list_flags.precision = (list_flags.precision * 10) + (flag[i] - 48);
		else if (flag[i] == '*')
			list_flags = ft_cut_star(list_flags, argv);
		i++;
	}
	return (list_flags);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	argv;
	t_lst	list_flags;

	i = 0;
	count = 0;
	va_start(argv, str);
	while (str[i] != '\0')
	{
		count += (str[i] == '%') ? 0 : 1;
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			list_flags = ft_init(list_flags);
			list_flags = ft_cut_flags(&str[++i], list_flags, argv);
			while (ft_check_flag(str[i]))
				i++;
			count += ft_print_value(str[i], list_flags, argv);
		}
		else
			ft_putchar_fd(str[i], 1);
		i += (str[i] == '\0') ? 0 : 1;
	}
	va_end(argv);
	return (count);
}
