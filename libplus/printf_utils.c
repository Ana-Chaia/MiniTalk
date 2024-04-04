/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:57 by anacaro5          #+#    #+#             */
/*   Updated: 2024/02/05 13:14:16 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i += write(1, "(null)", 6);
	else
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_put_char(char c)
{
	int	i;

	i = 1;
	write(1, &c, 1);
	return (i);
}

int	ft_put_nbr(int n)
{
	long		num;
	const char	*str = "0123456789";
	int			i;

	num = (long)n;
	i = 0;
	if (n < 0)
	{
		num *= -1;
		i += write (1, "-", 1);
	}
	if (num > 9)
		i += ft_put_nbr(num / 10);
	i += write (1, &str[num % 10], 1);
	return (i);
}

int	ft_put_unsig(unsigned int n)
{
	const char	*str = "0123456789";
	int			i;

	i = 0;
	if (n > 9)
		i = ft_put_nbr(n / 10);
	i += write (1, &str[n % 10], 1);
	return (i);
}

int	ft_put_hexa(unsigned int n, char especifier)
{
	const char	*str = "0123456789abcdef";
	const char	*str2 = "0123456789ABCDEF";
	int			i;

	i = 0;
	if (n > 15)
		i = ft_put_hexa(n / 16, especifier);
	if (especifier == 'x')
		i += write (1, &str[n % 16], 1);
	else
		i += write (1, &str2[n % 16], 1);
	return (i);
}
