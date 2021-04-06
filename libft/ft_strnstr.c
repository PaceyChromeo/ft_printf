/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:35:40 by pjacob            #+#    #+#             */
/*   Updated: 2021/03/22 11:35:43 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	if (*little == '\0')
		return ((char *)big);
	len_little = ft_strlen(little);
	while (*big != '\0' && len-- >= len_little)
	{
		if (*big == *little && ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
