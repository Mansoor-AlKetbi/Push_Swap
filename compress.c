/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:52:01 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/21 12:18:58 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(int *orig, int n, int val)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < n)
	{
		if (orig[i] < val)
			rank++;
		i++;
	}
	return (rank);
}

void	compress_stack(t_stack *a)
{
	int		n;
	int		*orig;
	t_list	*cur;
	int		i;

	n = a->size;
	orig = malloc(n * sizeof(*orig));
	if (!orig)
		return ;
	cur = a->top;
	i = 0;
	while (cur)
	{
		orig[i++] = *(int *)cur->content;
		cur = cur->next;
	}
	cur = a->top;
	while (cur)
	{
		*(int *)cur->content = get_rank(orig, n, *(int *)cur->content);
		cur = cur->next;
	}
	free(orig);
}
