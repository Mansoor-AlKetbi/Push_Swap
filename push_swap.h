/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:03 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 13:28:39 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>


typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

typedef struct s_stack
{
    t_list  *top;
    int     size;
}   t_stack;

t_list  *ft_lstnew(void *content);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstdel(t_list **lst, void (*del)(void *));
t_list  *ft_lstpop_back(t_list **lst);
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_stack *init_stack(void);
void    swap(t_stack *stack);
void    push(t_stack *from, t_stack *to);
void    rotate(t_stack *stack);
void    reverse_rotate(t_stack *stack);
int     ft_atoi(const char *str);
int     is_number(char *str);
int     is_duplicate(t_stack *stack, int value);
int     parse_input(int argc, char **argv, t_stack *stack);
void    swap_elements(t_list *a, t_list *b);
void    sort_stack(t_stack *a, t_stack *b);
void    sort_2_num(t_stack *a, t_stack *b);
void    sort_3_num(t_stack *a, t_stack *b);
void    sort_4_num(t_stack *a, t_stack *b);
void    sort_5_num(t_stack *a, t_stack *b);
void radix_sort(t_stack *a, t_stack *b);
t_list *ft_lstlast(t_list *lst);
int get_max_bits(t_stack *stack);
void op_sa(t_stack *a, t_stack *b);
void op_sb(t_stack *a, t_stack *b);
void op_ss(t_stack *a, t_stack *b);
void op_pa(t_stack *a, t_stack *b);
void op_pb(t_stack *a, t_stack *b);
void op_ra(t_stack *a, t_stack *b);
void op_rb(t_stack *a, t_stack *b);
void op_rr(t_stack *a, t_stack *b);
void op_rra(t_stack *a, t_stack *b);
void op_rrb(t_stack *a, t_stack *b);
void op_rrr(t_stack *a, t_stack *b);
void push_min_to_b(t_stack *a, t_stack *b);
void compress_stack(t_stack *a);

#endif
