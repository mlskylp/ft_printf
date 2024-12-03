/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayaalp <mkayaalp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:26:19 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/12/03 17:13:19 by mkayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_transformation(char a, va_list args)
{
	if (a == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (a == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (a == 'p')
		return (ft_convert_to_hex(va_arg(args, void *)));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (a == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (a == 'x' || a == 'X')
		return (ft_convert_to_hex_lower(va_arg(args, unsigned int), a));
	else if (a == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

static int	format_check(const char n)
{
	if (n == 'c' || n == 's' || n == 'p' || n == 'd' || n == 'i' || n == 'u'
		|| n == 'x' || n == 'X' || n == '%')
		return (1);
	else
		return (-1);
}

int	ft_printf(const char *n, ...)
{
	va_list	args;
	int		len;
	int		temp;

	temp = 0;
	len = 0;
	if (!n)
		return (-1);
	va_start(args, n);
	while (*n)
	{
		if (*n == '%' && format_check(*(n + 1)) == 1)
		{
			n++;
			temp = ft_transformation(*n, args);
			if (temp == -1)
				return (-1);
			len += temp;
		}
		else if ((*n == '%' && format_check(*(n + 1)) == -1) || (++len
				&& ft_print_char(*n) == -1))
			return (-1);
		n++;
	}
	return (va_end(args), len);
}
//(*n == '%' && format_check(*(n + 1)) == -1) ||