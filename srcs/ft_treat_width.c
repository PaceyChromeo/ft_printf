/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:49:36 by pjacob            #+#    #+#             */
/*   Updated: 2021/04/05 15:02:14 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_treat_space(int size)
{
	char	*space;

	space = ft_calloc(size + 1, sizeof(*space));
	if (!space)
		return (NULL);
	ft_memset(space, ' ', size);
	space[size] = '\0';
	return (space);
}

void	ft_treat_str(char *str, t_flag *flags)
{
	char	*space;

	if (!str || (flags->prec == 0 && flags->dot))
	{
		space = ft_treat_space(flags->field);
		ft_putstr_fd(space, STDOUT_FILENO);
		free(space);
	}
	else if (flags->prec < (int)ft_strlen(str) && flags->prec > 0)
	{
		space = ft_treat_space(flags->field - flags->prec);
		ft_putstr_prec(str, flags->prec, space, flags);
		free(space);
	}
	else
	{
		space = ft_treat_space(flags->field - (int)ft_strlen(str));
		ft_putstr_prec(str, ft_strlen(str), space, flags);
		free(space);
	}
}

void	ft_treat_char(unsigned char c, size_t size, t_flag *flags)
{
	char	*space;
	char	*zero;

	space = ft_treat_space(size);
	if (flags->minus == 1)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		ft_putstr_fd(space, STDOUT_FILENO);
		free(space);
	}
	else if (c == '%' && flags->zero && !flags->minus)
	{
		free(space);
		zero = ft_treat_zero(size);
		ft_putstr_fd(zero, STDOUT_FILENO);
		ft_putchar_fd(c, STDOUT_FILENO);
		free(zero);
	}
	else
	{
		ft_putstr_fd(space, STDOUT_FILENO);
		ft_putchar_fd(c, STDOUT_FILENO);
		free (space);
	}
}

void	ft_treat_int(char *str, t_flag *flags)
{
	char	*space;
	int		l;

	l = ft_strlen(str);
	if (str[0] == '0' && flags->field && flags->dot && !flags->prec)
	{
		space = ft_treat_space(flags->field);
		ft_putstr_fd(space, STDOUT_FILENO);
		free(space);
	}
	else if ((flags->field > l && flags->dot && flags->prec <= l)
		 || (flags->field > l && !flags->dot))
	{
		space = ft_treat_space(flags->field - l);
		ft_putnbr_prec(str, space, flags);
		free(space);
	}
	else if (flags->field > l && flags->prec > l && flags->field > flags->prec)
	{
		space = ft_treat_space(flags->field - flags->prec);
		ft_putnbr_prec(str, space, flags);
		free(space);
	}
	else
		ft_putnbr_prec(str, "", flags);
}

void	ft_treat_hexa(int len, char *hexa, t_flag *flags)
{
	char	*space;

	if (hexa[0] == '0' && flags->field && flags->dot && !flags->prec)
	{
		space = ft_treat_space(flags->field);
		ft_putstr_fd(space, STDOUT_FILENO);
		free(space);
	}
	else if ((flags->field > len && flags->dot && flags->prec <= len)
		|| (flags->field > len && !flags->dot))
	{
		space = ft_treat_space(flags->field - len);
		ft_putnbr_hexa_prec(hexa, space, flags);
		free(space);
	}
	else if (flags->field > len && flags->prec > len
		 && flags->field > flags->prec)
	{
		space = ft_treat_space(flags->field - flags->prec);
		ft_putnbr_hexa_prec(hexa, space, flags);
		free(space);
	}
	else
		ft_putnbr_hexa_prec(hexa, "", flags);
}
