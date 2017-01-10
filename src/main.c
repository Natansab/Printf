/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:25:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/10 19:05:00 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf(const char* restrict format, ...)
{
  int i;
  int sum  = 0;
  char *str;
	t_vars parsed;
  va_list list;

  va_start(list, format);
  while ((str = strchr(format, '%')))
  {
    if (str > format)
        ft_putstr(ft_strndup(format, str - format));
		if (str[1] == '%')
				ft_putchar('%');
		else if (str[1] != '%')
			{
        ft_initialize_vars(&parsed);
				ft_get_flags(str + 1, &parsed);

        // Handling s
        if (strchr("s", (int)parsed.type))
        {
          if (!strcmp(parsed.flag, "l"))
              ft_print_parsed_value(va_arg(list, char*), &parsed);
          if (strcmp(parsed.flag, "l"))
              ft_print_parsed_value((char*)va_arg(list, wchar_t*), &parsed);
        }

        // Handling c
        if (strchr("c", (int)parsed.type))
          ft_print_parsed_value(ctostr((char)va_arg(list, int)), &parsed);

        // Handling p
        if (strchr("p", (int)parsed.type))
          ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 16, "0123456789abcdef"), &parsed);

        // Handling o
        if (strchr("o", (int)parsed.type))
        {
          ft_handler_o(list, parsed);
        //   if (!parsed.flag)
        //     ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 8, "01234567"), &parsed);
        //   else if (strcmp(parsed.flag, "l"))
        //     ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long int), 8, "01234567"), &parsed);
        //   else if (strcmp(parsed.flag, "ll"))
        //     ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long long int), 8, "01234567"), &parsed);
        //   else if (strcmp(parsed.flag, "h"))
        //     ft_print_parsed_value(ft_itoa_base((unsigned short)va_arg(list, int), 8, "01234567"), &parsed);
        //   else if (strcmp(parsed.flag, "hh"))
        //     ft_print_parsed_value(ft_itoa_base((unsigned char)va_arg(list, int), 8, "01234567"), &parsed);
        //   else if (strcmp(parsed.flag, "j"))
        //     ft_print_parsed_value(ft_itoa_base((size_t)va_arg(list, size_t), 8, "01234567"), &parsed);
        //   else if (strcmp(parsed.flag, "z"))
        //     ft_print_parsed_value(ft_itoa_base((uintmax_t)va_arg(list, uintmax_t), 8, "01234567"), &parsed);
        }

        // Handling O
        if (strchr("O", (int)parsed.type))
            ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long int), 8, "01234567"), &parsed);


        // Handling x
        if (strchr("x", (int)parsed.type))
        {
          if (!parsed.flag)
            ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 16, "0123456789abcdef"), &parsed);
          else if (strcmp(parsed.flag, "l"))
            ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long int), 16, "0123456789abcdef"), &parsed);
          else if (strcmp(parsed.flag, "ll"))
            ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long long int), 16, "0123456789abcdef"), &parsed);
          else if (strcmp(parsed.flag, "h"))
            ft_print_parsed_value(ft_itoa_base((unsigned short)va_arg(list, int), 16, "0123456789abcdef"), &parsed);
          else if (strcmp(parsed.flag, "hh"))
            ft_print_parsed_value(ft_itoa_base((unsigned char)va_arg(list, int), 16, "0123456789abcdef"), &parsed);
          else if (strcmp(parsed.flag, "j"))
            ft_print_parsed_value(ft_itoa_base((size_t)va_arg(list, size_t), 16, "0123456789abcdef"), &parsed);
          else if (strcmp(parsed.flag, "z"))
            ft_print_parsed_value(ft_itoa_base((uintmax_t)va_arg(list, uintmax_t), 16, "0123456789abcdef"), &parsed);
        }

        // Handling X
        if (strchr("X", (int)parsed.type))
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

        // Handling u
        if (strchr("u", (int)parsed.type))
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
        // Handling U
        if (strchr("U", (int)parsed.type))
            ft_print_parsed_value(ft_itoa(va_arg(list, unsigned long int)), &parsed);


        // Handling di
        if (strchr("di", (int)parsed.type))
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

        // Handling D
        if (strchr("D", (int)parsed.type))
            ft_print_parsed_value(ft_itoa(va_arg(list, long int)), &parsed);


        // if (strchr("oxXu", (int)parsed.type) && !parsed.flag)
        // {
        //   if (strchr("x", (int)parsed.type))
        //     ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 16, "0123456789abcdef"), &parsed);
        //   if (strchr("X", (int)parsed.type))
        //     ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 16, "0123456789ABCDEF"), &parsed);
        //   if (strchr("o", (int)parsed.type))
        //     ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int), 8, "01234567"), &parsed);
        //   if (strchr("u", (int)parsed.type))
        //     ft_print_parsed_value(ft_itoa(va_arg(list, unsigned int)), &parsed);
        //  }
        // // if (strchr("oxXu", (int)parsed.type) && parsed.flag)
        // // {
        // //   if (strcmp(parsed.flag, "l"))
        // //     va_arg(list, unsigned long int);
        // //   if (strcmp(parsed.flag, "ll"))
        // //     va_arg(list, unsigned long long int);
        // //   /* Since shot < int va_arg only accepts int and not short */
        // //   if (strcmp(parsed.flag, "h") || strcmp(parsed.flag, "hh"))
        // //     va_arg(list, unsigned int);
        // //   if (strcmp(parsed.flag, "j"))
        // //     va_arg(list, size_t);
        // //   if (strcmp(parsed.flag, "z"))
        // //      va_arg(list, uintmax_t);
        // //  }

        // // Dealing with di
        // if (strchr("di", (int)parsed.type) && !parsed.flag)
        // {
        //   ft_print_parsed_value(ft_itoa(va_arg(list, int)), &parsed);
        // }
        // if (strchr("di", (int)parsed.type) && parsed.flag)
        // {
        //   if (strcmp(parsed.flag, "l"))
        //     ft_print_parsed_value(ft_itoa(va_arg(list, long int)), &parsed);
        //   if (strcmp(parsed.flag, "ll"))
        //     ft_print_parsed_value(ft_itoa(va_arg(list, long long int)), &parsed);
        //   /* Since short < int va_arg only accepts int and not short */
        //   if (strcmp(parsed.flag, "h") || strcmp(parsed.flag, "hh"))
        //     ft_print_parsed_value(ft_itoa(va_arg(list, int)), &parsed);
        //   if (strcmp(parsed.flag, "j"))
        //     ft_print_parsed_value(ft_itoa(va_arg(list, size_t)), &parsed);
        //   if (strcmp(parsed.flag, "z"))
        //      ft_print_parsed_value(ft_itoa(va_arg(list, intmax_t)), &parsed);
        //  }
         // Once the value is stored we need
         // to mix all the flags + value to print everything
        //  ft_print_parsed_value(&parsed);
       }
  i = 0;
  while (!strchr(("sSpdDioOuUxXcC"), (int)str[i]))
    i++;
	format = str + i + 1;
	}
  if (format != NULL)
    ft_putstr(format);
  va_end(list);

  return (sum);
}

int main(void)
{

 printf("teste de la conversion S %s\n", "סדפסדפ");
// ft_printf("teste de la conversion S %s\n", "סדפסדפ");
  // printf("teste de la conversion c %c\n", 's');
  // ft_printf("teste de la conversion c %c\n", 's');
 //  char *p;
 //  //wchar_t c = 'כ';
 // // wchar_t str[] = L"סאדלפכ";
  //  p = "hello";
  //  ft_printf("mon pointeur vaut %p\n", p);
  //  printf("et avec printf %p\n", p);
  //  ft_printf("mon x vaut %x\n", -15684);
  //  printf("mon x vaut %x\n", -15684);
  // ft_printf("avec ft_printf d et i %lli\n", (long long int)5465454654);
  // printf("avec printf d et i    %lli\n", (long long int)5465454654);
  // printf("et avec printf %x\n", -15684);
  // printf("printf hho %o\n", 23234);
  ft_printf("ft_printf hho %o\n", 23234);

	//ft_printf("hello ישראל i am %-+4i and my name is %.5s. What about you? My hebrew name is %s", 24, "Natan", "ישראל");
  // printf("a hebrew character %s\n", "⏚  ♷");
    //printf("%-400.s", "hello");
    // printf("|%zu|\n", 452);
    //  printf("|%jx|\n", 452);
    //  printf("|%jX|\n", 452);
    //  printf("|%jo|\n", 452);
    //printf("|%jp|\n", ptr);
    // // printf("|%ji|\n", i);

	  return (0);
}
