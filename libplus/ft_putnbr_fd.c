/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:22:36 by anacaro5          #+#    #+#             */
/*   Updated: 2023/11/02 14:36:18 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long		num;
	const char	*str = "0123456789";

	num = (long)n;
	if (n < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}	
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	write (fd, &str[num % 10], 1);
}
