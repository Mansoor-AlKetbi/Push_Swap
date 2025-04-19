/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:28:52 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 13:24:34 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    a.top  = NULL;
    a.size = 0;
    b.top  = NULL;
    b.size = 0;

    if (argc < 2)
        return (0);

    if (!parse_input(argc, argv, &a))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    compress_stack(&a);
    sort_stack(&a, &b);
    ft_lstdel(&a.top, free);
    return (0);
}


void sort_stack(t_stack *a, t_stack *b)
{
    if (a->size <= 1)
        return;
    if (a->size == 2)
        sort_2_num(a, b);
    else if (a->size == 3)
        sort_3_num(a, b);
    else if (a->size == 4)
        sort_4_num(a, b);
    else if (a->size == 5)
        sort_5_num(a, b);
    else
        radix_sort(a, b);
}
