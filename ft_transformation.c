/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayaalp <mkayaalp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:42:38 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/11/30 16:54:40 by mkayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (*s != '\0')
	{
		ft_print_char(*s);
		s++;
		len++;
	}
	return (len);
}
