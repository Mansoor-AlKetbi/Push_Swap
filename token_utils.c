/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:17:58 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/21 12:26:22 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tokens(int argc, char **argv)
{
	int		total;
	int		i;
	char	**parts;
	int		j;

	total = 0;
	i = 1;
	while (i < argc)
	{
		parts = ft_split(argv[i], ' ');
		j = 0;
		while (parts[j])
			j++;
		total += j;
		free_split(parts);
		i++;
	}
	return (total);
}

static void	fill_tokens(int argc, char **argv, char **tokens)
{
	int		i;
	int		idx;
	char	**parts;
	int		j;

	idx = 0;
	i = 1;
	while (i < argc)
	{
		parts = ft_split(argv[i], ' ');
		j = 0;
		while (parts[j])
		{
			tokens[idx++] = parts[j];
			j++;
		}
		free(parts);
		i++;
	}
	tokens[idx] = NULL;
}

int	build_tokens(int argc, char **argv, char ***out_tokens, int *out_tc)
{
	int		total;
	char	**tokens;

	total = count_tokens(argc, argv);
	tokens = malloc((total + 1) * sizeof(*tokens));
	if (!tokens)
		return (0);
	fill_tokens(argc, argv, tokens);
	*out_tokens = tokens;
	*out_tc = total;
	return (1);
}
