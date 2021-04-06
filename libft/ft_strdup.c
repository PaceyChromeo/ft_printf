/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:27:14 by pjacob            #+#    #+#             */
/*   Updated: 2021/03/22 12:04:55 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*copy;
	size_t		i;

	i = -1;
	copy = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	while (++i < ft_strlen(s))
		*(copy + i) = *(s + i);
	copy[i] = '\0';
	return (copy);
}
