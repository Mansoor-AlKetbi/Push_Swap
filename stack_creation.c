/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:28 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 12:20:18 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *init_stack(void)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}


void swap(t_stack *stack)
{
    if (stack->size < 2)
        return ;
    t_list *first = stack->top;
    t_list *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void push(t_stack *from, t_stack *to)
{
    if (from->size == 0)
        return ;
    t_list *node = from->top;
    from->top = from->top->next;
    node->next = to->top;
    to->top = node;
    from->size--;
    to->size++;
}

void rotate(t_stack *stack)
{
    if (stack->size < 2)
        return ;
    t_list *first = stack->top;
    stack->top = first->next;
    first->next = NULL;
    ft_lstadd_back(&stack->top, first);
}

void reverse_rotate(t_stack *stack)
{
    t_list *last;
    if (stack->size < 2)
        return ;
        last = ft_lstpop_back(&stack->top);
        ft_lstadd_front(&stack->top, last);
}