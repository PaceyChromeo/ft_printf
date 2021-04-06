/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacey <pacey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:59:07 by pacey             #+#    #+#             */
/*   Updated: 2021/04/04 22:58:06 by pacey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	void	ft_put_uint(unsigned int n)
{
	if (n > 9)
		ft_put_uint(n / 10);
	ft_putchar_fd((char)(n % 10 + '0'), STDOUT_FILENO);
}

static int	ft_dispatch_uint(char *temp, unsigned int nbr,
		 int len, t_flag *flags)
{
	int	count;

	count = 0;
	if (nbr == 0 && flags->dot && !flags->prec && !flags->field)
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
		if (flags->field == 1 && !nbr && flags->dot && !flags->prec)
			ft_putchar_fd(' ', STDOUT_FILENO);
		else
			ft_put_uint(nbr);
		return (len);
	}
}

int	ft_get_uint(va_list args, t_flag *flags)
{	
	char			*temp;
	int				len;
	unsigned int	nbr;
	int				count;

	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	nbr = (unsigned int)va_arg(args, unsigned int);
	temp = ft_uitoa(nbr);
	len = ft_strlen(temp);
	count = ft_dispatch_uint(temp, nbr, len, flags);
	free(temp);
	return (count);
}
