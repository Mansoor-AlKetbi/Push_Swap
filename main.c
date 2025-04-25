/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:28:52 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/25 16:20:56 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* main.c */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	make_it_null(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**tokens;
	int		must_free;
	int		tc;

	make_it_null(&a, &b);
	if (argc < 2)
		return (0);
	must_free = build_tokens(argc, argv, &tokens, &tc);
	if (!parse_input(tc, tokens, &a))
	{
		write(2, "Error\n", 6);
		if (must_free)
			free_split(tokens);
		return (1);
	}
	if (must_free)
		free_split(tokens);
	compress_stack(&a);
	sort_stack(&a, &b);
	ft_lstdel(&a.top, free);
	return (0);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 1)
		return ;
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
