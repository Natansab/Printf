/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctostr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:29:19 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/10 18:32:37 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *ctostr(char c)
{
  char *str;

  if (!(str = (char*)malloc(sizeof(*str) * 2)))
    return NULL;
  str[0] = c;
  str[1] = '\0';
  return (str);
}
