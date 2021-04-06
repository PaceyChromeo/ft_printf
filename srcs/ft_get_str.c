/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:42:02 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 09:14:49 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int	ft_dispatch_str(char *str, int len, t_flag *flags)
{
	if (flags->field >= len || (flags->field < len
			&& flags->prec < flags->field && flags->dot))
	{
		ft_treat_str(str, flags);
		return (flags->field);
	}
	else if (flags->prec < len && flags->field <= flags->prec && flags->dot)
	{
		ft_putstr_prec(str, flags->prec, "", flags);
		return (flags->prec);
	}
	else
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		return (len);
	}
}

void	ft_putstr_prec(char *str, size_t size, char *space, t_flag *flags)
{
	size_t	i;

	i = 0;
	if (flags->minus == 1 && space)
	{
		while (i < size)
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			i++;
		}
		ft_putstr_fd(space, STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(space, STDOUT_FILENO);
		while (i < size)
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			i++;
		}
	}
}

int	ft_get_str(va_list args, t_flag *flags)
{
	char	*str;
	int		len;
	int		count;

	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	str = va_arg(args, char *);
	if (!str)
	{
		if (flags->dot && !flags->prec && flags->field < 2)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	count = ft_dispatch_str(str, len, flags);
	return (count);
}
