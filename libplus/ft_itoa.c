/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:00:01 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/31 18:09:39 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}	
	return (len);
}

char	*ft_itoa(int n)
{
	int		lenght;
	char	*str;
	int		temp;
	long	num;

	num = (long)n;
	temp = n;
	if (n == 0)
		return (ft_strdup("0"));
	lenght = ft_numlen(n);
	str = (char *)malloc((lenght + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	str[lenght] = '\0';
	if (num < 0)
		num *= -1;
	while (lenght > 0)
	{
		lenght--;
		str[lenght] = (num % 10) + '0';
		num /= 10;
	}
	if (temp < 0)
		str[0] = '-';
	return (str);
}	
