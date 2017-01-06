/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:27:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/06 15:32:49 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/includes/libft.h"

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
}             t_vars;

char *ft_get_flags(char *str, t_vars *parsed);

#endif
