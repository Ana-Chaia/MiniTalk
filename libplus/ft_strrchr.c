/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:15:39 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/27 17:42:02 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	size_t	i;
	char	*last;

	i = 0;
	last = NULL;
	if (chr > 255)
	{
		chr = chr % 256;
	}
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)chr)
		{
			last = (char *)&str[i];
		}
		i++;
	}
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (last);
}
