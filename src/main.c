/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:25:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/07 19:59:08 by nsabbah          ###   ########.fr       */
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
				ft_get_flags(str + 1, &parsed);

        // Dealing with the poxXu
        if (strchr("poxXu", (int)parsed.type) && !parsed.flag)
          va_arg(list, unsigned int);
        if (strchr("oxXu", (int)parsed.type) && parsed.flag)
        {
          if (strcmp(parsed.flag, "l"))
            va_arg(list, unsigned long int);
          if (strcmp(parsed.flag, "ll"))
            va_arg(list, unsigned long long int);
          /* Since shot < int va_arg only accepts int and not short */
          if (strcmp(parsed.flag, "h") || strcmp(parsed.flag, "hh"))
            va_arg(list, unsigned int);
          if (strcmp(parsed.flag, "j"))
            va_arg(list, size_t);
          if (strcmp(parsed.flag, "z"))
             va_arg(list, uintmax_t);
         }

        // Dealing with di
        if (strchr("di", (int)parsed.type) && !parsed.flag)
          va_arg(list, int);
        if (strchr("di", (int)parsed.type) && parsed.flag)
        {
          if (strcmp(parsed.flag, "l"))
            va_arg(list, long int);
          if (strcmp(parsed.flag, "ll"))
            va_arg(list, long long int);
          /* Since shot < int va_arg only accepts int and not short */
          if (strcmp(parsed.flag, "h") || strcmp(parsed.flag, "hh"))
            va_arg(list, int);
          if (strcmp(parsed.flag, "j"))
            va_arg(list, size_t);
          if (strcmp(parsed.flag, "z"))
             va_arg(list, intmax_t);
         }
         // Once the value is stored we need
         // to mix all the flags + value to print everything
         ft_print_parsed_value(&parsed);
       }
	format = str + 1;
	}
  if (format != NULL)
    ft_putstr(format);
  va_end(list);
  //
  // printf("\nspace is : %i\n", parsed.space);
	// printf("\nzero is : %i\n", parsed.zero);
	// printf("hashtag is : %i\n", parsed.hashtag);
	// printf("plus is : %i\n", parsed.plus);
	// printf("minus is : %i\n", parsed.minus);
	// printf("type is : %c\n", parsed.type);
	// printf("width is : %i\n", parsed.width);
	// printf("precision is : %i\n", parsed.precision);
	// printf("flag is : %s\n", parsed.flag);
	// printf("ptr2data is : %p\n", parsed.ptr2data);

  return (sum);
}

int main(void)
{
		ft_printf("%090000i", 120,222,222,222,121);
    // printf("|%zu|\n", 452);
    //  printf("|%jx|\n", 452);
    //  printf("|%jX|\n", 452);
    //  printf("|%jo|\n", 452);
    //printf("|%jp|\n", ptr);
    // // printf("|%ji|\n", i);

	  return (0);
}
