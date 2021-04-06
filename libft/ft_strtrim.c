/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:36:49 by pjacob            #+#    #+#             */
/*   Updated: 2021/03/22 11:36:52 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	start;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && check_set(s1[start], set))
		start++;
	len = start;
	while (s1[len])
		len++;
	while (start < len && check_set(s1[len - 1], set))
		len--;
	trim = ft_substr(s1, start, len - start);
	return (trim);
}
