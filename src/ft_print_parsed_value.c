/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parsed_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:14:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/11 15:47:16 by nsabbah          ###   ########.fr       */
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

  void ft_handle_hashtag(t_vars *parsed, char **str)
  {
    if (strchr("o", parsed->type))
      *str = ft_strjoin("0", *str);
    if (strchr("x", parsed->type))
      *str = ft_strjoin("0x", *str);
    if (strchr("X", parsed->type))
      *str = ft_strjoin("0X", *str);
  }

  void ft_handle_minus(t_vars *parsed, char **str)
   {
    while (ft_strlen(*str) < (size_t)parsed->width)
      *str = ft_strjoin(*str, " ");
    }

  void ft_handle_width(t_vars *parsed, char **str)
   {
    while (ft_strlen(*str) < (size_t)parsed->width)
    *str = ft_strjoin(" ", *str);
    }

    void ft_handle_zero(t_vars *parsed, char **str)
     {
      if (parsed->dot && parsed->type == 'i')
      {
        ft_handle_width(parsed, str);
        return ;
      }
      while (ft_strlen(*str) < (size_t)parsed->width)
      *str = ft_strjoin("0", *str);
      }

    void ft_handle_precision(t_vars *parsed, char **str)
    {
      if (strchr("sS", parsed->type))
        *str = strndup(*str, parsed->precision);
      if (strchr("diouxX", parsed->type))
        while (ft_strlen(*str) < (size_t)parsed->precision && ft_strlen(*str) < (size_t)parsed->width)
          *str = ft_strjoin("0", *str);
    }

void ft_print_parsed_value(char *str, t_vars *parsed)
{
  if (parsed->dot && strchr("sSdiouxX", parsed->type))
    ft_handle_precision(parsed, &str);
  if (parsed->plus && strchr("di", parsed->type))
    ft_handle_plus(&str);
  if (parsed->space && !parsed->plus && strchr("di", parsed->type))
    ft_handle_space(&str);
  // if ft_atoi(str) = 0 do nothing
  if (parsed->hashtag && strchr("oxXSp", parsed->type) && ft_atoi(str))
     ft_handle_hashtag(parsed, &str);
  if (parsed->minus)
     ft_handle_minus(parsed, &str);
  if (parsed->zero && !parsed->minus && strchr("diouxX", parsed->type))
    ft_handle_zero(parsed, &str);
  if (parsed->width && (!parsed->zero || !parsed->minus))
    ft_handle_width(parsed, &str);

  ft_putstr(str);
  //
  // printf("\nspace is : %i\n", parsed->space);
  // printf("zero is : %i\n", parsed->zero);
  // printf("hashtag is : %i\n", parsed->hashtag);
  // printf("plus is : %i\n", parsed->plus);
  // printf("minus is : %i\n", parsed->minus);
  // printf("type is : %c\n", parsed->type);
  // printf("width is : %i\n", parsed->width);
  // printf("precision is : %i\n", parsed->precision);
  // printf("flag is : %s\n", parsed->flag);
  // printf("ptr2data is : %p\n", parsed->ptr2data);
 }
