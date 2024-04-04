/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:55:15 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/27 18:15:27 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i_d;
	size_t	i_s;

	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i_d = size_dest;
	i_s = 0;
	while (src[i_s] != '\0' && i_d + i_s + 1 < size)
	{
		dst[i_d + i_s] = src[i_s];
		i_s++;
	}
	dst[i_d + i_s] = '\0';
	if (size_dest < size)
		return (size_dest + size_src);
	return (size + size_src);
}
