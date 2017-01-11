/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:25:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/11 20:32:43 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_flag_error(t_vars *parsed)
{
  // Too many flags
  if (parsed->minus > 1 || parsed->zero > 1 || parsed->plus > 1 || parsed->space > 1 || parsed->hashtag > 1 ||
          parsed->dot > 1)
      parsed->flag_error = 1;

  // Wrong modificators / special-flags
    // "pOUDS" should'nt have flag associated
   if (strchr("pOUDS", (int)parsed->type) && parsed->flag)
     parsed->flag_error = 2;
    // "sc" types can only have "l" flag
   if (strchr("sc", (int)parsed->type) && parsed->flag
         && strcmp(parsed->flag, "l"))
     parsed->flag_error = 3;
   // "+" && " " can only be associated to "di"
   if (!strchr("di", (int)parsed->type) && (parsed->plus || parsed->space))
     parsed->flag_error = 4;
   // "#" should only work with "xXp"
   if (!strchr("xXo", (int)parsed->type) && parsed->hashtag)
     parsed->flag_error = 5;
}

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
    {
				ft_putchar('%');
        format = str + 2;
    }
		else
			{
        ft_initialize_vars(&parsed);
				ft_get_flags(str + 1, &parsed);
        ft_flag_error(&parsed);
        //
        // if (parsed.flag_error)
        //   printf("parsed.flag_error vaut %i\n", parsed.flag_error);
        //   return (0);

        // Handling s
        if (strchr("s", (int)parsed.type))
        {
          if (!parsed.flag)
                ft_print_parsed_value(va_arg(list, char*), &parsed);
          else if (!strcmp(parsed.flag, "l"))
              ft_print_parsed_value((char*)va_arg(list, wchar_t*), &parsed);
        }

        // Handling c
        if (strchr("c", (int)parsed.type))
          ft_print_parsed_value(ctostr((char)va_arg(list, int)), &parsed);
        // Handling c
        // if (strchr("C", (int)parsed.type))
        //   ft_print_parsed_value(ctostr((wint_lt)va_arg(list, wint_t)), &parsed);

        // Handling p
        if (strchr("p", (int)parsed.type))
          ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned int),
            16, "0123456789abcdef"), &parsed);

        // Handling o
        if (strchr("o", (int)parsed.type))
          ft_handler_o(list, parsed);

        // Handling O
        if (strchr("O", (int)parsed.type))
            ft_print_parsed_value(ft_itoa_base(va_arg(list, unsigned long int),
              8, "01234567"), &parsed);

        // Handling x
        if (strchr("x", (int)parsed.type))
           ft_handler_x(list, parsed);

        // Handling X
        if (strchr("X", (int)parsed.type))
           ft_handler_upx(list, parsed);

        // Handling u
        if (strchr("u", (int)parsed.type))
          ft_handler_u(list, parsed);

        // Handling U
        if (strchr("U", (int)parsed.type))
            ft_print_parsed_value(ft_itoa(va_arg(list, unsigned long int)),
              &parsed);

        // Handling di
        if (strchr("di", (int)parsed.type))
          ft_handler_di(list, parsed);

        // Handling D
        if (strchr("D", (int)parsed.type))
            ft_print_parsed_value(ft_itoa(va_arg(list, long int)), &parsed);

        i = 0;
        while (!strchr(("sSpdDioOuUxXcC"), (int)str[i]))
          i++;
        format = str + i + 1;
       }
	}
  if (format != NULL)
    ft_putstr(format);
  va_end(list);

  return (sum);
}

int main(void)
{

//  printf("teste de la conversion S %s\n", "סדפסדפ");
// ft_printf("teste de la conversion S %s\n", "סדפסדפ");
//   printf("teste de la conversion c %c\n", 's');
//   ft_printf("teste de la conversion c %c\n", 's');
//   char *p;
//   //wchar_t c = 'כ';
//  // wchar_t str[] = L"סאדלפכ";
//    p = "hello";
//    ft_printf("mon pointeur vaut %p\n", p);
//    printf("et avec printf %p\n", p);
//   //  ft_printf("mon x vaut %x\n", -15684);
//   printf("mon x vaut %X\n", -15684);
//   // ft_printf("avec ft_printf d et i %lli\n", (long long int)5465454654);
//   // printf("avec printf d et i    %lli\n", (long long int)5465454654);
//   ft_printf("et avec printf %X\n", -15684);
//   // printf("printf hho %o\n", 23234);
//   ft_printf("ft_printf hho %o\n", 23234);
//
// 	ft_printf("hello ישראל i am %-+4i and my name is %.5s. What about you? My hebrew name is %s", 24, "Natan", "ישראל");
    // printf("a unicode character %csdfs%xd\n", 'a', 12344532);
    // ft_printf("a unicode character %csdfs%xd\n", 'a', 12344532);
    //printf("a unicode character %lc\n", L'⏚');
   //printf("ft_strlen d'un character unicode vaut %zu\n", ft_strlen("ח"));
//     printf("%-400.s", "hello");
//     printf("%#X\n", 150);
     //ft_printf("hello : %llc et %o\n", 150, -150, 1324);
//     printf("hello : %+s et %+X\n", "hello", -150);
// ft_printf("hello %#o asdf\n", 123);
// ft_printf("hello %#o asdf\n", 0);

// ft_printf("hello %#s asdf\n", 0);
//printf("test de la precision avec des int %10.5i|\n", 123);
// ft_printf("test de la precision avec des int %10s|\n", "hello");
// ft_printf("test de la precision avec des int %10i|\n", 123);
// printf("test de la precision avec des int %10i|\n", 123);
//ft_printf("test de la precision avec des int %% %10.2x|\n", 10023);
// printf("test de la precision avec des int %10.2x|\n", 10023);
//      printf("|%jx|\n", 452);
//      printf("|%jX|\n", 452);
//      printf("|%jo|\n", 452);
//     printf("|%jp|\n", ptr);
//     // printf("|%ji|\n", i);

//Tests Marine
// ft_printf("\n>> FT_PRINTF > .7s\nLiberté : %.7s\n", "J ecris ton nom");
//         printf("\n** PRINTF > .7s\nLiberté : %.7s\n", "J ecris ton nom");
//         printf("\n##########################\n");
//   ft_printf("\n>> FT_PRINTF > wchar + .7s\nLiberté : %.7s\n", "J’écris ton nom");
//         printf("\n** PRINTF > wchar + .7s\nLiberté : %.7s\n", "J’écris ton nom");
//         printf("\n##########################\n");
//   ft_printf("\n>> FT_PRINTF > wchar + S + L\nLiberté : %S\n", L"J’écris ton nom");
//         printf("\n** PRINTF > wchar + S + L\nLiberté : %S\n", L"J’écris ton nom");
//         printf("\n##########################\n");
//         printf("\n** PRINTF\n%5.10d\n%10.5d\n%010d\n%-10.2d\n% .5i\n% .2i\n% .1i\n%-.2u\n%#.2o\n%.2x\n%#.2X\n", 42, 42, 43, 44, 45, 42, 43, 44, 45, 46, 47);
//   ft_printf("\n>> FT_PRINTF\n%5.10d\n%10.5d\n%010d\n%-10.2d\n% .5i\n% .2i\n% .1i\n%-.2u\n%#.2o\n%.2x\n%#.2X\n", 42, 42, 43, 44, 45, 42, 43, 44, 45, 46, 47);
//         printf("\n##########################\n");
        printf("\n** PRINTF < 0\n%5.10d|\n%05d|\n%-10.2d|\n% .5i\n%2u|\n%#.2o|\n%.x|\n%#X|\n", -42, -42, -42, -42, -42, -42, -42, -42);
  ft_printf("\n>> FT_PRINTF < 0\n%5.10d|\n%05d|\n%-10.2d|\n% .5i\n%2u|\n%#.2o|\n%.x|\n%#x|\n", -42, -42, -42, -42, -42, -42, -42, -42);
//  ft_printf("\n>> FT_PRINTF < 0|\n%.x \n%#X|\n", -42, -42);
  //ft_printf("\n>> FT_PRINTF < 0|\n%.x", -42);

//   printf("\n** PRINTF < 0\n%-10.2d\n\n", -42);
// ft_printf("\n>> FT_PRINTF < 0\n%-10.2d\n\n", -42);


// ft_printf("test %#X\n", 1000);
// ft_printf("test %#X\n", -10);
// ft_printf("test %s\n", ft_itoa_base(-10, 16, "0123456789ABCDEF"));

// printf("%1.10i\n", 2);
// ft_printf("%1.10i\n", 2);
	  return (0);
}
