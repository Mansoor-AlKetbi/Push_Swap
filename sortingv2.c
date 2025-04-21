/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:20 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/20 15:04:04 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	bits;
	int	num;

	size = a->size;
	bits = get_max_bits(a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)a->top->content;
			if (((num >> i) & 1) == 0)
				op_pb(a, b);
			else
				op_ra(a, b);
			j++;
		}
		while (b->size > 0)
			op_pa(a, b);
		i++;
	}
}

int	get_max_bits(t_stack *stack)
{
	int		max;
	t_list	*current;
	int		bits;

	max = 0;
	current = stack->top;
	while (current)
	{
		if (*(int *)(current->content) > max)
			max = *(int *)(current->content);
		current = current->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
