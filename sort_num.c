/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:03:44 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/21 08:10:08 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_num(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		push_min_to_b(a, b);
		sort_3_num(a, b);
		op_pa(a, b);
	}
}

void	sort_5_num(t_stack *a, t_stack *b)
{
	if (a->size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_3_num(a, b);
		op_pa(a, b);
		op_pa(a, b);
	}
}
