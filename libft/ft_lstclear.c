/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacey <pacey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:31:14 by pacey             #+#    #+#             */
/*   Updated: 2021/03/22 11:02:51 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the memory of all elements of lst with del and free(3).
	The initial pointer is set to NULL.
Returns nothing.*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
}
