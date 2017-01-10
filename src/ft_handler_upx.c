/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_upx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:00:54 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/10 19:11:28 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_handler_upx(va_list list, t_vars parsed)
{
  if (!parsed.flag)
    ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 16, "0123456789ABCDEF"), &parsed);
  else if (strcmp(parsed.flag, "l"))
    ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long int), 16, "0123456789ABCDEF"), &parsed);
  else if (strcmp(parsed.flag, "ll"))
    ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long long int), 16, "0123456789ABCDEF"), &parsed);
  else if (strcmp(parsed.flag, "h"))
    ft_print_parsed_value(ft_itoa_base((unsigned short)va_arg(list, int), 16, "0123456789ABCDEF"), &parsed);
  else if (strcmp(parsed.flag, "hh"))
    ft_print_parsed_value(ft_itoa_base((unsigned char)va_arg(list, int), 16, "0123456789ABCDEF"), &parsed);
  else if (strcmp(parsed.flag, "j"))
    ft_print_parsed_value(ft_itoa_base((size_t)va_arg(list, size_t), 16, "0123456789ABCDEF"), &parsed);
  else if (strcmp(parsed.flag, "z"))
    ft_print_parsed_value(ft_itoa_base((uintmax_t)va_arg(list, uintmax_t), 16, "0123456789ABCDEF"), &parsed);
}
