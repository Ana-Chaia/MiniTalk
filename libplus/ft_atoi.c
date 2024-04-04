/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:19:08 by anacaro5          #+#    #+#             */
/*   Updated: 2023/10/31 15:03:42 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *strn)
{	
	int	sign;
	int	change;
	int	i;

	sign = 1;
	change = 0;
	i = 0;
	while (strn[i] == ' ' || strn[i] == '\t'
		|| strn[i] == '\n' || strn[i] == '\r'
		|| strn[i] == '\f' || strn[i] == '\v')
		i++;
	if (strn[i] == '-' || strn[i] == '+')
		sign = 1 - 2 * (strn[i++] == '-');
	while (strn[i] >= '0' && strn[i] <= '9')
		change = 10 * change + (strn[i++] - '0');
	return (change * sign);
}
