/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:00:54 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/10 19:02:28 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_handler_o(va_list list, t_vars parsed)
{
  if (!parsed.flag)
    ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 8, "01234567"), &parsed);
  else if (strcmp(parsed.flag, "l"))
    ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long int), 8, "01234567"), &parsed);
  else if (strcmp(parsed.flag, "ll"))
    ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long long int), 8, "01234567"), &parsed);
  else if (strcmp(parsed.flag, "h"))
    ft_print_parsed_value(ft_itoa_base((unsigned short)va_arg(list, int), 8, "01234567"), &parsed);
  else if (strcmp(parsed.flag, "hh"))
    ft_print_parsed_value(ft_itoa_base((unsigned char)va_arg(list, int), 8, "01234567"), &parsed);
  else if (strcmp(parsed.flag, "j"))
    ft_print_parsed_value(ft_itoa_base((size_t)va_arg(list, size_t), 8, "01234567"), &parsed);
  else if (strcmp(parsed.flag, "z"))
    ft_print_parsed_value(ft_itoa_base((uintmax_t)va_arg(list, uintmax_t), 8, "01234567"), &parsed);
}
