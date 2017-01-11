/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:07:05 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/11 14:09:22 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_initialize_vars(t_vars *parsed)
{
	parsed->minus = 0;
	parsed->zero = 0;
	parsed->plus = 0;
	parsed->width = 0;
	parsed->space = 0;
	parsed->hashtag = 0;
	parsed->flag = 0;
	parsed->flagnbr = 0;
	parsed->type = 0;
	parsed->precision = 0;
	parsed->dot = 0;
	parsed->flag_error = 0;
}
