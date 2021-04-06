/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:51:09 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 09:26:37 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int	ft_dispatch_int(int len, int n, char *temp, t_flag *flags)
{
	int	count;

	count = 0;
	if (!n && flags->dot && !flags->prec && !flags->field)
		return (0);
	else if (flags->field > len || flags->prec > len)
	{
		ft_treat_int(temp, flags);
		if (flags->field >= flags->prec)
			count = flags->field;
		else
			count = flags->prec;
		return (count);
	}
	else
	{
		if (flags->field == 1 && !n && flags->dot && !flags->prec)
			ft_putchar_fd(' ', STDOUT_FILENO);
		else
			ft_putnbr_fd(n, STDOUT_FILENO);
		return (len);
	}
}

int	ft_get_int(va_list args, t_flag *flags)
{
	char	*temp;
	int		len;
	int		n;
	int		count;

	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	n = va_arg(args, int);
	if (n < 0)
	{
		flags->neg = 1;
		if (flags->dot)
			flags->prec += 1;
	}
	temp = ft_itoa(n);
	len = ft_strlen(temp);
	count = ft_dispatch_int(len, n, temp, flags);
	free (temp);
	return (count);
}
