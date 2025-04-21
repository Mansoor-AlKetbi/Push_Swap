/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:28:44 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 11:39:23 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*prev;
	t_list	*last;

	if (!lst || !*lst)
		return (NULL);
	if (!(*lst)->next)
	{
		last = *lst;
		*lst = NULL;
		return (last);
	}
	prev = *lst;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	return (last);
}
