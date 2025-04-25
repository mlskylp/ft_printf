/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayaalp <mkayaalp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:42:38 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/12/03 17:40:10 by mkayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (ft_print_char(*s) == -1)
			return (-1);
		s++;
		len++;
	}
	return (len);
}
