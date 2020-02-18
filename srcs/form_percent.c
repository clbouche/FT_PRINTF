/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:59:49 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/18 11:33:34 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		form_percent(t_utils *utils, t_flags flags, va_list arg)
{
	int i;

	i = 0;
	(void)arg;
	utils->len = 1;
	if (flags.minus == 1 && flags.number > 1)
	{
		flags.zero = 0;
		ft_putchar_fd('%', 1);
		ft_justify(flags, utils);
	}
	else if (!flags.minus)
	{
		ft_justify(flags, utils);
		ft_putchar_fd('%', 1);
	}
	else
		ft_putchar_fd('%', 1);
	utils->rtn += 1;
	return (utils->rtn);
}
