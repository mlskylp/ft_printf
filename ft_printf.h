/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayaalp <mkayaalp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:16:58 by mkayaalp          #+#    #+#             */
/*   Updated: 2024/12/02 16:12:28 by mkayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_convert_to_hex(void *args);
int		ft_convert_to_hex_lower(unsigned int args, char a);
int		ft_putnbr(long n);
int		ft_printf(const char *n, ...);

#endif