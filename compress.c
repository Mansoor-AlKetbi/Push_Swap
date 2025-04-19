/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:52:01 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 13:28:37 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void compress_stack(t_stack *a)
{
    t_list *cur;
    t_list *cmp;
    int x;

    cur = a->top;
    while (cur)
    {
        x = 0;
        cmp = a->top;
        while (cmp)
        {
            if (*(int *)cmp->content < *(int *)cur->content)
                x++;
            cmp = cmp->next;
        }
        *(int *)cur->content = x;
        cur = cur->next;
    }
}