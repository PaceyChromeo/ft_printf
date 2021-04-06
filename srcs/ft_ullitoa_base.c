/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:20:31 by pjacob            #+#    #+#             */
/*   Updated: 2021/04/05 15:59:45 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_len_ull_hexa(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb < 16)
		return (1);
	else
	{
		while (nb)
		{
			nb /= 16;
			len++;
		}
		return (len);
	}
}

char	*ft_ullitoa_base(unsigned long long nbr, char *base)
{
	char				*hexa;
	int					i;

	i = ft_len_ull_hexa(nbr);
	hexa = ft_calloc(sizeof(char), i + 2);
	if (!hexa)
		return (NULL);
	hexa[i--] = '\0';
	while (nbr > 0)
	{
		hexa[i] = base[nbr % 16];
		nbr /= 16;
		i--;
	}
	return (hexa);
}
