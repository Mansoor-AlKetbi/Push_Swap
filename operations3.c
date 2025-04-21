/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:35:01 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/20 17:49:55 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_list	*cur;
	int		min;

	cur = a->top;
	min = *(int *)cur->content;
	while (cur)
	{
		if (*(int *)cur->content < min)
			min = *(int *)cur->content;
		cur = cur->next;
	}
	while (*(int *)a->top->content != min)
		op_ra(a, b);
	op_pb(a, b);
}
