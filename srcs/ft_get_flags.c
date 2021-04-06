/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:16:34 by pjacob            #+#    #+#             */
/*   Updated: 2021/04/05 14:37:16 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_isnt_convert(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int	ft_flag_on(t_flag *flags)
{
	if (flags->star_f || flags->field || flags->minus
		|| flags->prec || flags->zero || flags->star_p || flags->dot)
		return (1);
	return (0);
}

static	int	ft_parse_dot(char *str_fl, int i, t_flag *flags)
{
	int	index;
	int	j;

	index = i;
	flags->dot = 1;
	index++;
	if (str_fl[index] == '*')
		flags->star_p = 1;
	else if (ft_isdigit(str_fl[index]))
	{	
		j = index;
		while (ft_isdigit(str_fl[j]))
			j++;
		flags = ft_treat_prec(&str_fl[index], j - index, flags);
		index = j;
	}
	return (index);
}

static	t_flag	*ft_parse_flags_str(char *str_fl, t_flag *flags)
{
	int	i;
	int	j;

	i = 0;
	while (str_fl[i])
	{
		while (str_fl[i] == '0' || str_fl[i] == '-' || str_fl[i] == '*')
		{
			flags = ft_treat_flag(str_fl[i], flags);
			i++;
		}
		if (str_fl[i] >= '1' && str_fl[i] <= '9')
		{	
			j = i;
			while (ft_isdigit(str_fl[j]))
				j++;
			flags = ft_treat_minfield(&str_fl[i], j - i, flags);
			i = j;
		}
		if (str_fl[i] == '.')
			i = ft_parse_dot(str_fl, i, flags);
		i++;
	}
	return (flags);
}

t_flag	*ft_get_flags(const char *str, int i, t_flag *flags)
{
	char	*str_fl;
	int		j;
	int		len;

	j = i;
	while (ft_isnt_convert(str[j]) && !ft_isspace(str[j]) && str)
		j++;
	len = j - i;
	str_fl = ft_calloc(len + 2, sizeof(*str_fl));
	if (!str_fl)
		return (0);
	str_fl = ft_strncpy(str_fl, &str[i], len);
	str_fl[len] = '\0';
	flags = ft_parse_flags_str(str_fl, flags);
	flags->index = i + len;
	free(str_fl);
	return (flags);
}
