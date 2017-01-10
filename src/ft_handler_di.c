/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:00:54 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/10 19:14:45 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_handler_di(va_list list, t_vars parsed)
{
  if (!parsed.flag)
    ft_print_parsed_value(ft_itoa(va_arg(list, int)), &parsed);
  else if (strcmp(parsed.flag, "l"))
    ft_print_parsed_value(ft_itoa(va_arg(list, long int)), &parsed);
  else if (strcmp(parsed.flag, "ll"))
    ft_print_parsed_value(ft_itoa((long long)va_arg(list, long long int)), &parsed);
  else if (strcmp(parsed.flag, "h"))
    ft_print_parsed_value(ft_itoa((short)va_arg(list, int)), &parsed);
  else if (strcmp(parsed.flag, "hh"))
    ft_print_parsed_value(ft_itoa((char)va_arg(list, int)), &parsed);
  else if (strcmp(parsed.flag, "j"))
    ft_print_parsed_value(ft_itoa((size_t)va_arg(list, size_t)), &parsed);
  else if (strcmp(parsed.flag, "z"))
    ft_print_parsed_value(ft_itoa((intmax_t)va_arg(list, uintmax_t)), &parsed);
}
