/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:20 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 11:39:37 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack *a, t_stack *b)
{
    int i, j, size, bits;
    int num;

    bits = get_max_bits(a);
    size = a->size;
    for (i = 0; i < bits; i++)
    {
        j = 0;
        while (j < size)
        {
            num = *(int *)(a->top->content);
            if (((num >> i) & 1) == 0)
                push(a, b);  // Move number to stack b if the current bit is 0.
            else
                rotate(a);
            j++;
        }
        while (b->size > 0)
            push(b, a);  // Return all numbers back to stack a.
    }
}

int get_max_bits(t_stack *stack)
{
    int max = 0;
    t_list *current = stack->top;
    while (current)
    {
        if (*(int *)(current->content) > max)
            max = *(int *)(current->content);
        current = current->next;
    }
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}
