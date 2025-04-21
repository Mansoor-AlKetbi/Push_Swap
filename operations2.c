/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:19:15 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/20 17:48:31 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *a, t_stack *b)
{
	(void)b;
	rotate(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *a, t_stack *b)
{
	(void)a;
	rotate(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	op_rra(t_stack *a, t_stack *b)
{
	(void)b;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
