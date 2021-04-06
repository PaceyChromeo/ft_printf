/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:55:29 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 17:11:21 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int	ft_dispatch_spe(char *hexa, int len, long nbr, t_flag *flags)
{
	int	count;

	count = len;
	if (flags->ptr && nbr)
		ft_putstr_fd("0x", STDOUT_FILENO);
	if (flags->ptr && flags->field <= 2
		&& !nbr && flags->dot && flags->prec <= 2)
		ft_putstr_fd("0x", STDOUT_FILENO);
	else
	{
		if (!flags->ptr && flags->field == 1
			&& !nbr && flags->dot && !flags->prec)
			ft_putchar_fd(' ', STDOUT_FILENO);
		else
			ft_putstr_fd(hexa, STDOUT_FILENO);
	}
	return (count);
}

void	ft_putnbr_hexa_spe(char *hexa, char *space, int len, t_flag *flags)
{
	char	*zero;

	if (flags->prec > len)
	{
		zero = ft_treat_zero(flags->prec - len);
		ft_putnbr_zero(space, zero, hexa, flags);
		free(zero);
	}
	else if (flags->minus == 0 && flags->zero == 1 && !flags->dot)
	{
		zero = ft_treat_zero(ft_strlen(space));
		ft_putstr_fd(zero, STDOUT_FILENO);
		if (flags->ptr && hexa[0] != '0')
			ft_putstr_fd("0x", STDOUT_FILENO);
		ft_putstr_fd(hexa, STDOUT_FILENO);
		free(zero);
	}
	else if (hexa[0] == '0' && !flags->prec)
		ft_putnbr_with_zero(space, flags);
}

void	ft_putnbr_hexa_prec(char *hexa, char *space, t_flag *flags)
{
	int		len;

	len = (int)ft_strlen(hexa);
	if (flags->prec > len || (hexa[0] == '0' && !flags->prec)
		|| (!flags->minus && flags->zero && !flags->dot))
		ft_putnbr_hexa_spe(hexa, space, len, flags);
	else
	{
		if (flags->minus == 1)
		{
			if (flags->ptr && hexa[0] != '0')
				ft_putstr_fd("0x", STDOUT_FILENO);
			ft_putstr_fd(hexa, STDOUT_FILENO);
			ft_putstr_fd(space, STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(space, STDOUT_FILENO);
			if (flags->ptr && hexa[0] != '0')
				ft_putstr_fd("0x", STDOUT_FILENO);
			ft_putstr_fd(hexa, STDOUT_FILENO);
		}
	}
}

int	ft_dispatch_hexa(char *hexa, int len, long nbr, t_flag *flags)
{
	int	count;

	count = 0;
	if ((!flags->ptr && !nbr && flags->dot && !flags->prec && !flags->field)
		|| (flags->field > len || flags->prec > len))
	{
		count = ft_hexa_spe(nbr, hexa, len, flags);
		return (count);
	}
	else
	{
		count = ft_dispatch_spe(hexa, len, nbr, flags);
		return (count);
	}
}

int	ft_get_hexa(va_list args, char c, t_flag *flags)
{
	int					len;
	unsigned int		nbr;
	char				*hexa;
	int					count;

	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	nbr = va_arg(args, unsigned int);
	if (c == 'X')
		hexa = ft_uitoa_base(nbr, BASE_HEXA_UP);
	else
		hexa = ft_uitoa_base(nbr, BASE_HEXA_DOWN);
	len = ft_strlen(hexa);
	count = ft_dispatch_hexa(hexa, len, nbr, flags);
	free(hexa);
	return (count);
}
