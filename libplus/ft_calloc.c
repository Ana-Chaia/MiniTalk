/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:15 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/27 18:13:55 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size_bytes)
{
	size_t			total_size;
	void			*memory;
	size_t			i;
	unsigned char	*ptr;

	total_size = n_elem * size_bytes;
	if (n_elem == 0 || size_bytes == 0)
		return (malloc(0));
	if (total_size / n_elem != size_bytes)
		return (NULL);
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	ptr = (unsigned char *)memory;
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (memory);
}
