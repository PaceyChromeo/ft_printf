/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:37:06 by pjacob            #+#    #+#             */
/*   Updated: 2021/03/22 11:37:09 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	str_len = ft_strlen(s) - start;
	if (len > str_len)
		len = str_len;
	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	if (start < ft_strlen(s))
	{
		free(str);
		str = ft_calloc(sizeof(char), len + 1);
		if (!str)
			return (NULL);
		str = ft_strncpy(str, s + start, len);
	}
	return (str);
}
