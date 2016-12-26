/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:25:53 by nsabbah           #+#    #+#             */
/*   Updated: 2016/12/26 14:05:14 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdio.h>
#include <stdarg.h>

// void ft_printf(const char* restrict format, ...)
// {
//
// }

int ft_printf(const char* restrict format, ...)
{
  int sum  = 0;
  char *str;
  va_list list;

  va_start(list, format);
  while ((str = strchr(format, '%')))
  {
    if (str > format)
        ft_putstr(strndup(format, str - format));
    if (str[1] == 's')
      ft_putstr(va_arg(list, char*));
    else if (str[1] == 'i')
      ft_putnbr(va_arg(list, int));
    format = str + 2;
  }
  if (format != NULL)
    ft_putstr(format);
  va_end(list);
  return (sum);
}

int main(void)
{
   ft_printf("Salut %s as tu %i ans ?", "Natan", 21);
  return (0);
}
