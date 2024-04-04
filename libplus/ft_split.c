/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:19:43 by anacaro5          #+#    #+#             */
/*   Updated: 2023/11/01 18:47:26 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count);
}

static	size_t	ft_sizestr(char const *s, char c)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	j;
	size_t	k;
	size_t	count;

	count = ft_countstr(s, c);
	new = (char **)malloc (sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	new[count] = NULL;
	j = 0;
	while (j < count)
	{
		new[j] = (char *)malloc (sizeof(char) * (ft_sizestr(s, c) + 1));
		if (!new[j])
			return (NULL);
		while (*s && *s == c)
			s++;
		k = 0;
		while (*s && *s != c)
			new[j][k++] = *s++;
		new[j][k] = '\0';
		j++;
	}
	return (new);
}
