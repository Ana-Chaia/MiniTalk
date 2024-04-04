/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:19:19 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/27 18:22:03 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s)
		return (dest);
	if (s < d && s + n > d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n -1];
			n--;
		}
	}
	else
	{	
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}
