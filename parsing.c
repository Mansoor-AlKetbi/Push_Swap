/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:18 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 14:08:07 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(char *str)
{
    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int is_duplicate(t_stack *stack, int value)
{
    t_list *current = stack->top;

    while (current)
    {
        if (*(int *)(current->content) == value)
            return (1);
        current = current->next;
    }
    return (0);
}


int parse_input(int ac, char **av, t_stack *stack)
{
    int     i;
    long    tmp;
    int    *num_ptr;
    t_list *new_node;

    i = 1;
    while (i < ac)
    {
        if (!is_number(av[i]))
            return (0);
        tmp = ft_atoi(av[i]);
        if (tmp > INT_MAX || tmp < INT_MIN)
            return (0);
        if (is_duplicate(stack, (int)tmp))
            return (0);

        num_ptr = malloc(sizeof(*num_ptr));
        if (!num_ptr)
            return (0);
        *num_ptr = (int)tmp;

        new_node = ft_lstnew(num_ptr);
        if (!new_node)
        {
            free(num_ptr);
            return (0);
        }
        ft_lstadd_back(&stack->top, new_node);
        stack->size++;
        i++;
    }
    return (1);
}

