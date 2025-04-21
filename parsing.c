/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:18 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/21 08:24:47 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
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

int	is_duplicate(t_stack *stack, int value)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		if (*(int *)(current->content) == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	add_number(t_stack *stack, int val)
{
	int		*num;
	t_list	*node;

	num = malloc(sizeof(*num));
	if (!num)
		return (0);
	*num = val;
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		return (0);
	}
	ft_lstadd_back(&stack->top, node);
	stack->size++;
	return (1);
}

int	parse_input(int ac, char **av, t_stack *stack)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		tmp = ft_atoi(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		if (is_duplicate(stack, (int)tmp))
			return (0);
		if (!add_number(stack, (int)tmp))
			return (0);
		i++;
	}
	return (1);
}
