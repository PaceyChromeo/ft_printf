/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:35:27 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 14:47:05 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_get_char(va_list args, t_flag *flags)
{
	unsigned char	c;

	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	c = (unsigned char)va_arg(args, int);
	if (flags->field && !flags->prec)
	{
		ft_treat_char(c, flags->field - 1, flags);
		return (flags->field);
	}
	else if (c == '\0')
		ft_putchar_fd('\0', STDOUT_FILENO);
	else
		ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
