/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:47:36 by pacey             #+#    #+#             */
/*   Updated: 2021/04/05 17:04:08 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*ft_treat_ptr_null(t_flag *flags)
{
	char	*hexa;

	if (!flags->dot)
		hexa = ft_strdup("0x0");
	else
		hexa = ft_strdup("");
	return (hexa);
}

int	ft_get_pointer(va_list args, t_flag *flags)
{
	int				len;
	unsigned long	n;
	char			*ptr;
	int				count;

	flags->ptr = 1;
	if (flags->star_f || flags->star_p)
		ft_treat_star(args, flags);
	n = va_arg(args, unsigned long);
	if (!n)
		ptr = ft_treat_ptr_null(flags);
	else
		ptr = ft_ullitoa_base(n, BASE_HEXA_DOWN);
	len = ft_strlen(ptr);
	if (n || (!n && flags->dot))
		len += 2;
	count = ft_dispatch_hexa(ptr, len, n, flags);
	free(ptr);
	return (count);
}
