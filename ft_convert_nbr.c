/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayaalp <mkayaalp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:41 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/12/03 17:13:10 by mkayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr(long n)
{
	int	len;
	int	a;

	len = 0;
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		len = write(1, "-", 1);
		if (len == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	a = ft_print_char((n % 10) + 48);
	if (a == -1)
		return (-1);
	return (len + 1);
}
