/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:53:29 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/21 07:48:23 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_allocate(char	**tab, char const	*s, char sep)

{
	char		**rep;
	char const	*tmp;

	tmp = s;
	rep = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*rep = ft_substr(s, 0, tmp - s);
			s = tmp;
			++rep;
		}
	}
	*rep = NULL;
}

static int	ft_count_words(char const	*s, char sep)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word;
		while (*s && *s != sep)
			++s;
	}
	return (word);
}

char	**ft_split(char const	*s, char c)
{
	char	**a;
	int		space;

	if (!s)
		return (NULL);
	space = ft_count_words(s, c);
	a = (char **)malloc(sizeof(char *) * (space + 1));
	if (!a)
		return (NULL);
	ft_allocate(a, s, c);
	return (a);
}
