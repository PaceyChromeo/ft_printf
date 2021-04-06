/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:50:26 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 17:16:15 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flag	ft_flag_init(void)
{
	t_flag	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.field = 0;
	flags.prec = 0;
	flags.star_f = 0;
	flags.star_p = 0;
	flags.index = 0;
	flags.dot = 0;
	flags.neg = 0;
	flags.ptr = 0;
	return (flags);
}

int	ft_putstr(const char *str, int i, va_list args, t_flag *flags)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_get_char(args, flags);
	else if (str[i] == 's')
		count += ft_get_str(args, flags);
	else if (str[i] == 'p')
		count += ft_get_pointer(args, flags);
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_get_int(args, flags);
	else if (str[i] == 'u')
		count += ft_get_uint(args, flags);
	else if (str[i] == 'x')
		count += ft_get_hexa(args, 'x', flags);
	else if (str[i] == 'X')
		count += ft_get_hexa(args, 'X', flags);
	else if (str[i] == '%')
		count += ft_get_percent(args, flags);
	else if (ft_isspace(str[i]))
	{
		ft_putchar_fd(str[i], STDOUT_FILENO);
		count = 1;
	}
	return (count);
}

int	ft_get_args(const char *str, int i, va_list args, t_flag *flags)
{
	int	count;

	count = 0;
	if (ft_isnt_convert(str[i]))
	{
		flags = ft_get_flags(str, i, flags);
		i = flags->index;
	}
	count += ft_putstr(str, i, args, flags);
	return (count);
}

int	ft_parse_str(const char *str, va_list args)
{
	size_t	i;
	int		count;
	t_flag	flags;

	i = -1;
	count = 0;
	if (!str)
		return (0);
	while (str[++i])
	{
		flags = ft_flag_init();
		if (str[i] != '%')
			count += ft_putchar_fd_count(str[i]);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (count);
			count += ft_get_args(str, i, args, &flags);
			if (ft_flag_on(&flags))
				i = flags.index;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, str);
	count += ft_parse_str(str, args);
	va_end(args);
	return (count);
}
