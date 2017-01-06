/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:25:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/06 15:47:12 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../includes/ft_printf.h"

static void	ft_putnbrbase_fd_inner(uintmax_t nbr, char *base, size_t baselen,
				int fd)
{
	if (nbr >= baselen)
	{
		ft_putnbrbase_fd_inner(nbr / baselen, base, baselen, fd);
		ft_putnbrbase_fd_inner(nbr % baselen, base, baselen, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

void		ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd)
{
	ft_putnbrbase_fd_inner(nbr, base, 16, fd);
}

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
        ft_putstr(ft_strndup(format, str - format));
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
	  t_vars parsed;

	  ft_get_flags("#+  02249.309i", &parsed);
	  printf("space is : %i\n", parsed.space);
	  printf("hashtag is : %i\n", parsed.hashtag);
	  printf("plus is : %i\n", parsed.plus);
	  printf("minus is : %i\n", parsed.minus);
	  printf("type is : %c\n", parsed.type);
	  printf("width is : %i\n", parsed.width);
	  printf("precision is : %i\n", parsed.precision);
	  printf("flag is : %s\n", parsed.flag);
	  return (0);
}
