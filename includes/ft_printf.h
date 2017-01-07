/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:27:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/07 19:19:36 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_vars {
  int   hashtag;
  int   zero;
  int   minus;
  int   plus;
  int   space;
  int   width;
  int   precision;
  char  type;
  char* flag;
  void* ptr2data;
}             t_vars;

char *ft_get_flags(char *str, t_vars *parsed);
void	ft_initialize_vars(t_vars *parsed);
void ft_print_parsed_value(t_vars *parsed);

#endif
