/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:56:20 by mal-ketb          #+#    #+#             */
/*   Updated: 2025/04/19 22:57:43 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup2(const char *s1, size_t leng, unsigned int start)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (leng + 1));
	if (!str)
		return (NULL);
	while (i < leng)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*pt;
	size_t			j;

	i = start;
	j = ft_strlen(s);
	if (start > j)
	{
		pt = malloc(sizeof(char));
		pt[0] = '\0';
		return (pt);
	}
	if (len > ft_strlen(s))
		return (ft_strdup2(s, j - start, start));
	pt = malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	while (s[i] && i - start < len)
	{
		pt[i - start] = s[i];
		i++;
	}
	pt[i - start] = '\0';
	return (pt);
}
