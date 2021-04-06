/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miscelleanous.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:24:01 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 17:16:33 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_putnbr_with_zero_minus(char *space, t_flag *flags)
{
	if (flags->ptr)
		ft_putstr_fd("0x0", STDOUT_FILENO);
	else
	{
		if (flags->dot)
			ft_putchar_fd(' ', STDOUT_FILENO);
		else
			ft_putchar_fd('0', STDOUT_FILENO);
	}
	ft_putstr_fd(space, STDOUT_FILENO);
}

void	ft_putnbr_with_zero(char *space, t_flag *flags)
{
	if (flags->minus)
		ft_putnbr_with_zero_minus(space, flags);
	else
	{
		ft_putstr_fd(space, STDOUT_FILENO);
		if (flags->ptr)
			ft_putstr_fd("0x0", STDOUT_FILENO);
		else
		{
			if (flags->dot)
				ft_putchar_fd(' ', STDOUT_FILENO);
			else
				ft_putchar_fd('0', STDOUT_FILENO);
		}
	}
}

int	ft_hexa_spe(long nbr, char *hexa, int len, t_flag *flags)
{
	int	count;

	if (!nbr && flags->dot && !flags->prec && !flags->field)
	{
		if (flags->ptr)
		{
			ft_putstr_fd(hexa, STDOUT_FILENO);
			return (len);
		}
		else
			return (0);
	}
	else
	{
		ft_treat_hexa(len, hexa, flags);
		if (flags->field >= flags->prec)
			count = flags->field;
		else
			count = flags->prec;
		return (count);
	}
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_putchar_fd_count(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
