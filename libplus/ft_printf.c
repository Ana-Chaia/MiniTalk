/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:11:59 by anacaro5          #+#    #+#             */
/*   Updated: 2024/02/05 13:13:38 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_pointer(unsigned long n)
{
	const char	*str = "0123456789abcdef";
	int			i;

	i = 0;
	if (!n)
		i += write (1, "(nil)", 5);
	else
	{
		if (n > 15)
			i = ft_put_pointer(n / 16);
		i += write (1, &str[n % 16], 1);
	}
	return (i);
}

int	ft_print_pref(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
	{
		i += ft_put_pointer(n);
		return (i);
	}
	i = 2;
	write(1, "0x", 2);
	i += ft_put_pointer(n);
	return (i);
}

int	ft_check_n_print(const char *str, int *idx, va_list ap)
{
	int	count;

	count = 0;
	(idx[0])++;
	if (str[(idx[0])] == 's')
		count += ft_put_str(va_arg(ap, char *));
	else if (str[(idx[0])] == '%')
		count += write (1, (&str[(idx[0])]), 1);
	else if (str[(idx[0])] == 'c')
		count += ft_put_char((char)va_arg(ap, int));
	else if (str[(idx[0])] == 'd' || str[(idx[0])] == 'i')
		count += ft_put_nbr(va_arg(ap, int));
	else if (str[(idx[0])] == 'u')
		count += ft_put_unsig(va_arg(ap, unsigned int));
	else if (str[(idx[0])] == 'x' || str[(idx[0])] == 'X')
		count += ft_put_hexa(va_arg(ap, unsigned int), (str[(idx[0])]));
	else if (str[(idx[0])] == 'p')
		count += ft_print_pref(va_arg(ap, unsigned long));
	(idx[0])++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argpointer;
	int		count;
	int		i;

	va_start(argpointer, format);
	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_check_n_print(format, &i, argpointer);
		else
		{
			write (1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(argpointer);
	return (count);
}
