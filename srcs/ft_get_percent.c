/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 07:51:10 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 15:16:32 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_get_percent(va_list args, t_flag *flags)
{
	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	if (flags->field)
	{
		ft_treat_char('%', flags->field - 1, flags);
		return (flags->field);
	}
	else
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		return (1);
	}
}
