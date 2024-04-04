/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:55:32 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/30 16:17:53 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	len_s = 0;
	if (!s)
		return (NULL);
	while (s[len_s] != '\0')
		len_s++;
	if (len_s < start)
		return (ft_strdup(""));
	if (len >= len_s)
		new = (char *)malloc (len_s - start + 1);
	else
		new = (char *)malloc (len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (len-- > 0 && s[start] != '\0')
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
