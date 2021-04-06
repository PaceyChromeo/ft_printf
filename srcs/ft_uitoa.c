/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacey <pacey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:50:38 by pacey             #+#    #+#             */
/*   Updated: 2021/04/03 11:30:25 by pacey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_len_nb(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr < 10)
		return (1);
	else
	{
		while (nbr)
		{
			nbr /= 10;
			len++;
		}
		return (len);
	}
}

static int	ft_len_ui_hexa(long long nb)
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

static char	*ft_treat_ui_hexa(long long nbr, char *base)
{
	char				*hexa;
	int					i;

	if (nbr < 0)
	{
		nbr *= -1;
		nbr = 4294967296 - nbr;
	}
	i = ft_len_ui_hexa(nbr);
	hexa = ft_calloc(sizeof(*hexa), i + 2);
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

char	*ft_uitoa_base(unsigned int nbr, char *base)
{
	long long	n;
	char		*hexa;

	if (nbr == 0)
		return (ft_strdup("0"));
	n = nbr;
	hexa = ft_treat_ui_hexa(n, base);
	return (hexa);
}

char	*ft_uitoa(unsigned int nbr)
{
	char			*str;
	int				i;
	unsigned int	n;

	n = nbr;
	i = ft_len_nb(n);
	str = ft_calloc(i + 2, sizeof(*str));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
