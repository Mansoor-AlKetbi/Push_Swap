/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:11 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/21 08:09:02 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	sort_2_num(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (*(int *)(a->top->content) > *(int *)(a->top->next->content))
			op_sa(a, b);
	}
}

static void	do_sa_rra(t_stack *a, t_stack *b)
{
	op_sa(a, b);
	op_rra(a, b);
}

static void	do_sa_ra(t_stack *a, t_stack *b)
{
	op_sa(a, b);
	op_ra(a, b);
}

void	sort_3_num(t_stack *a, t_stack *b)
{
	t_list	*x;
	t_list	*y;
	t_list	*z;
	int		xi;
	int		yi;

	x = a->top;
	y = x->next;
	z = y->next;
	xi = *(int *)x->content;
	yi = *(int *)y->content;
	if (xi > yi && yi < *(int *)z->content && xi < *(int *)z->content)
		op_sa(a, b);
	else if (xi > yi && yi > *(int *)z->content)
		do_sa_rra(a, b);
	else if (xi > yi && yi < *(int *)z->content && xi > *(int *)z->content)
		op_ra(a, b);
	else if (xi < yi && yi > *(int *)z->content && xi < *(int *)z->content)
		do_sa_ra(a, b);
	else if (xi < yi && yi > *(int *)z->content && xi > *(int *)z->content)
		op_rra(a, b);
}
