/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:11 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 12:20:23 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  

void swap_elements(t_list *a, t_list *b)
{
    void *temp;

    temp = a->content;
    a->content = b->content;
    b->content = temp;
}

void sort_2_num(t_stack *a, t_stack *b)
{
    if (a->size == 2)
    {
        if (*(int *)(a->top->content) > *(int *)(a->top->next->content))
            op_sa(a, b);
    }
}

void sort_3_num(t_stack *a, t_stack *b)
{
        t_list *x;
        t_list *y;
        t_list *z;
        int xi;
        int yi;
        int zi;

        x = a->top;
        y = x->next;
        z = y->next;
        xi = *(int *)x->content;
        yi = *(int *)y->content;
        zi = *(int *)z->content;
        if (xi > yi && yi < zi && xi < zi)
            op_sa(a, b);
        else if (xi > yi && yi > zi)
        {
            op_sa(a, b);
            op_rra(a, b);
        }
        else if (xi > yi && yi < zi && xi > zi)
            op_ra(a, b);
        else if (xi < yi && yi > zi && xi < zi)
        {
            op_sa(a, b);
            op_ra(a, b);
        }
        else if (xi < yi && yi > zi && xi > zi)
            op_rra(a, b);
}

void sort_4_num(t_stack *a, t_stack *b)
{
    if (a->size == 4)
    {
        push_min_to_b(a, b);
        sort_3_num(a, b);
        op_pa(a, b);
    }
}

void sort_5_num(t_stack *a, t_stack *b)
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
