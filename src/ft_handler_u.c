/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:00:54 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/10 19:12:38 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_handler_u(va_list list, t_vars parsed)
{
  if (!parsed.flag)
    ft_print_parsed_value(ft_itoa(va_arg(list, unsigned int)), &parsed);
  else if (strcmp(parsed.flag, "l"))
    ft_print_parsed_value(ft_itoa(va_arg(list, unsigned long int)), &parsed);
  else if (strcmp(parsed.flag, "ll"))
    ft_print_parsed_value(ft_itoa((unsigned long long)va_arg(list, unsigned long long int)), &parsed);
  else if (strcmp(parsed.flag, "h"))
    ft_print_parsed_value(ft_itoa((unsigned short)va_arg(list, int)), &parsed);
  else if (strcmp(parsed.flag, "hh"))
    ft_print_parsed_value(ft_itoa((unsigned char)va_arg(list, int)), &parsed);
  else if (strcmp(parsed.flag, "j"))
    ft_print_parsed_value(ft_itoa((size_t)va_arg(list, size_t)), &parsed);
  else if (strcmp(parsed.flag, "z"))
    ft_print_parsed_value(ft_itoa((uintmax_t)va_arg(list, uintmax_t)), &parsed);
}
