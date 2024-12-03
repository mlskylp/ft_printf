/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayaalp <mkayaalp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:04:45 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/12/03 18:15:02 by mkayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned long n)
{
	unsigned int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_hex(unsigned long n)
{
	char	*base_16;

	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (ft_print_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex(n / 16);
		ft_hex(n % 16);
	}
	return (0);
}

int	ft_convert_to_hex(void *args)
{
	unsigned int	len;

	if (args == 0)
	{
		if (ft_print_str("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (ft_print_str("0x") == -1)
		return (-1);
	len = ft_len_hex((unsigned long)args);
	ft_hex((unsigned long)args);
	return (len + 2);
}

int	ft_hex_lower(unsigned int n, char a, char *base_16)
{
	if (n < 16)
	{
		if (ft_print_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex_lower(n / 16, a, base_16);
		ft_hex_lower(n % 16, a, base_16);
	}
	return (0);
}

int	ft_convert_to_hex_lower(unsigned int args, char a)
{
	unsigned int	len;
	char			*base_16_low;
	char			*base_16_up;

	base_16_low = "0123456789abcdef";
	base_16_up = "0123456789ABCDEF";
	len = ft_len_hex((unsigned int)args);
	if (a == 'x')
		ft_hex_lower((unsigned int)args, a, base_16_low);
	else if (a == 'X')
		ft_hex_lower((unsigned int)args, a, base_16_up);
	if (len != 0)
		return (len);
	else
		return (1);
}
