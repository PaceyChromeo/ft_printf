/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:34:44 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 16:09:18 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	ft_putnbr_zero_no_min(char *zero, char *nbr, t_flag *flags)
{
	if (flags->neg)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		ft_putstr_fd(zero, STDOUT_FILENO);
		ft_putstr_fd(&nbr[1], STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(zero, STDOUT_FILENO);
		ft_putstr_fd(nbr, STDOUT_FILENO);
	}
}

static void	ft_putnbr_spe(char *nbr, char *space, int len, t_flag *flags)
{
	char	*zero;

	if (flags->prec > len)
	{
		zero = ft_treat_zero(flags->prec - len);
		ft_putnbr_zero(space, zero, nbr, flags);
		free(zero);
	}
	else if (!flags->minus && flags->zero && !flags->dot)
	{
		zero = ft_treat_zero(ft_strlen(space));
		ft_putnbr_zero_no_min(zero, nbr, flags);
		free(zero);
	}
	else if (nbr[0] == '0' && !flags->prec)
		ft_putnbr_with_zero(space, flags);
}

static void	ft_putnbr_neg(char *zero, char *nbr, t_flag *flags)
{
	if (flags->neg == 1)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		ft_putstr_fd(zero, STDOUT_FILENO);
		ft_putstr_fd(&nbr[1], STDOUT_FILENO);
	}
	else
	{
		if (flags->ptr)
			ft_putstr_fd("0x", STDOUT_FILENO);
		ft_putstr_fd(zero, STDOUT_FILENO);
		ft_putstr_fd(nbr, STDOUT_FILENO);
	}
}

void	ft_putnbr_zero(char *space, char *zero,
				char *nbr, t_flag *flags)
{
	if (flags->minus == 1)
	{
		ft_putnbr_neg(zero, nbr, flags);
		ft_putstr_fd(space, STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(space, STDOUT_FILENO);
		ft_putnbr_neg(zero, nbr, flags);
	}
}

void	ft_putnbr_prec(char *nbr, char *space, t_flag *flags)
{
	int		len;

	len = (int)ft_strlen(nbr);
	if (flags->prec > len || (nbr[0] == '0' && !flags->prec)
		|| (!flags->minus && flags->zero && !flags->dot))
	{
		ft_putnbr_spe(nbr, space, len, flags);
	}
	else
	{
		if (flags->minus == 1)
		{
			ft_putstr_fd(nbr, STDOUT_FILENO);
			ft_putstr_fd(space, STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(space, STDOUT_FILENO);
			ft_putstr_fd(nbr, STDOUT_FILENO);
		}
	}
}
