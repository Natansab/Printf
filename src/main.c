/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:25:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/06 16:10:33 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf(const char* restrict format, ...)
{
  int sum  = 0;
  char *str;
	t_vars parsed;
  va_list list;

	ft_initialize_vars(&parsed);
  va_start(list, format);
  while ((str = strchr(format, '%')))
  {
    if (str > format)
        ft_putstr(ft_strndup(format, str - format));
		if (str[1] == '%')
				ft_putchar('%');
		else if (str[1] != '%')
			{
				printf("str + 1 is %s", str + 1);
				ft_get_flags(str + 1, &parsed);
				parsed.ptr2data = va_arg(list, void*);
			}
	format = str + 1;
	}
  if (format != NULL)
    ft_putstr(format);
  va_end(list);

	printf("\nspace is : %i\n", parsed.space);
	printf("hashtag is : %i\n", parsed.hashtag);
	printf("plus is : %i\n", parsed.plus);
	printf("minus is : %i\n", parsed.minus);
	printf("type is : %c\n", parsed.type);
	printf("width is : %i\n", parsed.width);
	printf("precision is : %i\n", parsed.precision);
	printf("flag is : %s\n", parsed.flag);
	printf("ptr2data is : %p\n", parsed.ptr2data);

  return (sum);
}

int main(void)
{
	  //t_vars parsed;
	  // ft_get_flags("#+  02249.309i", &parsed);
	  // printf("space is : %i\n", parsed.space);
	  // printf("hashtag is : %i\n", parsed.hashtag);
	  // printf("plus is : %i\n", parsed.plus);
	  // printf("minus is : %i\n", parsed.minus);
	  // printf("type is : %c\n", parsed.type);
	  // printf("width is : %i\n", parsed.width);
	  // printf("precision is : %i\n", parsed.precision);
	  // printf("flag is : %s\n", parsed.flag);

		ft_printf("hello % 09i", 12);
	  return (0);
}
