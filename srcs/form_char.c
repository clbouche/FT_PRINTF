/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:30:38 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/13 11:38:11 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		form_char(t_utils *utils, t_flags flags, va_list arg)
{
	utils->c = va_arg(arg, int);
	utils->len = 1;
	if (flags.minus == 1 && flags.number > 1)
	{
		ft_putchar_printf(utils->c, utils);
		ft_justify(flags, utils);
	}
	else if (flags.minus == 0 && flags.number > 1)
	{
		ft_justify(flags, utils);
		ft_putchar_printf(utils->c, utils);
	}
	else
		ft_putchar_printf(utils->c, utils);
	return (utils->rtn);
}
