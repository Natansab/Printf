/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parsed_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:14:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/07 19:59:34 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void ft_handle_plus(char **str)
  {
    if (**str != '-')
      *str = ft_strjoin("+", *str);
  }

 void ft_handle_space(char **str)
  {
   if (**str != '-')
    *str = ft_strjoin(" ", *str);
   }

void ft_print_parsed_value(t_vars *parsed)
{
  // Everything will be store in a string before being printed
  char *str = "1000";
  if (parsed->plus && strchr("di", parsed->type))
    ft_handle_plus(&str);
  if (parsed->space && !parsed->plus && strchr("di", parsed->type))
    ft_handle_space(&str);
  printf("str is |%s|\n", str);
  // if (parsed->hashtag)
  //   ft_handle_hashtag(parsed, str);
  // if (parsed->minus)
  //   ft_handle_minus(parsed, str);

  //
  // printf("\nspace is : %i\n", parsed->space);
  // printf("\nzero is : %i\n", parsed->zero);
  // printf("hashtag is : %i\n", parsed->hashtag);
  // printf("plus is : %i\n", parsed->plus);
  // printf("minus is : %i\n", parsed->minus);
  // printf("type is : %c\n", parsed->type);
  // printf("width is : %i\n", parsed->width);
  // printf("precision is : %i\n", parsed->precision);
  // printf("flag is : %s\n", parsed->flag);
  // printf("ptr2data is : %p\n", parsed->ptr2data);



}
